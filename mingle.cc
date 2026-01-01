#include <G4VUserDetectorConstruction.hh>
#include <G4tgbVolumeMgr.hh>
class Detector : public G4VUserDetectorConstruction
{
  public:
    G4VPhysicalVolume* Construct() {
      G4tgbVolumeMgr::GetInstance()->AddTextFile("detector.tg");
      return G4tgbVolumeMgr::GetInstance()->ReadAndConstructDetector();
    } ///< load detector definition from a text file "detector.tg"
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

#include <G4RunManagerFactory.hh>
#include <G4PhysListFactory.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
int main(int argc, char** argv)
{
  auto run = G4RunManagerFactory::CreateRunManager();

  // load default physics list, or the one specified by $PHYSLIST
  G4PhysListFactory f; run->SetUserInitialization(f.ReferencePhysList());
  run->SetUserInitialization(new Detector); // load detector definition
  run->SetUserInitialization(new Action); // load particle generator

  if (argc == 1) { // interactive mode
    G4UIExecutive ui(argc, argv);
    ui.SessionStart();
  } else { // batch mode
    G4String command = "/control/execute ";
    G4UImanager::GetUIpointer()->ApplyCommand(command + argv[1]);
  }

  delete run;
}
