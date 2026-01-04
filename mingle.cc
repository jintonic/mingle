#include <G4VUserDetectorConstruction.hh>
#include <G4GlobalMagFieldMessenger.hh>
#include <G4tgbVolumeMgr.hh>
#include <G4AutoDelete.hh>
class Detector : public G4VUserDetectorConstruction
{
  public:
    G4VPhysicalVolume* Construct() {
      G4tgbVolumeMgr::GetInstance()->AddTextFile("detector.tg");
      return G4tgbVolumeMgr::GetInstance()->ReadAndConstructDetector();
    } ///< load detector definition from a text file "detector.tg"
    void ConstructSDandField() {
      G4AutoDelete::Register(new G4GlobalMagFieldMessenger());
    } ///< enable /globalField/ to set uniform B-field
};

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4GeneralParticleSource.hh>
class Generator : public G4VUserPrimaryGeneratorAction
{
  private:
    G4GeneralParticleSource* fGPS;
  public:
    Generator() : G4VUserPrimaryGeneratorAction() { fGPS = new G4GeneralParticleSource; }
    ~Generator() { delete fGPS; }
    void GeneratePrimaries(G4Event *evt) { fGPS->GeneratePrimaryVertex(evt); }
};
#include <G4VUserActionInitialization.hh>
class Action : public G4VUserActionInitialization
{
  public:
    void Build() const { SetUserAction(new Generator); }
};

#include <G4TScoreNtupleWriter.hh>
#include <G4RunManagerFactory.hh>
#include <G4PhysListFactory.hh>
#include <G4AnalysisManager.hh>
#include <G4ScoringManager.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
int main(int argc, char** argv)
{
  auto run = G4RunManagerFactory::CreateRunManager();
  G4ScoringManager::GetScoringManager();  // activate command-based scorer
  G4TScoreNtupleWriter<G4AnalysisManager> writer; // enable ntuple recording
  if (run->GetRunManagerType() != G4RunManager::sequentialRM)
    writer.SetNtupleMerging(true); // merge ntuples created in multi-threads
  // load default physics list, or the one specified by $PHYSLIST
  G4PhysListFactory f; run->SetUserInitialization(f.ReferencePhysList());
  run->SetUserInitialization(new Detector); // load detector definition
  run->SetUserInitialization(new Action); // load particle generator

  G4UIExecutive* ui = nullptr; // assume batch mode by default
  if (argc==1) ui = new G4UIExecutive(argc, argv); // interactive mode
  // enable visialization between UI creation and session start
  auto vis = new G4VisExecutive("quiet"); vis->Initialize();
  if (ui) { // start an interactive UI session
    ui->SessionStart(); delete ui; // clear memory at the end of UI session
  } else { // run a macro file in batch mode
    G4String cmd = "/control/execute ", macroFile = argv[1];
    G4UImanager::GetUIpointer()->ApplyCommand(cmd + macroFile);
  }

  delete vis;
  delete run;
}
// -*- C++; indent-tabs-mode:nil; tab-width:2 -*-
// vim: ft=cpp:ts=2:sts=2:sw=2:et
