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

#include <G4RunManagerFactory.hh>
#include <G4PhysListFactory.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
int main(int argc, char** argv)
{
  auto run = G4RunManagerFactory::CreateRunManager();
  // load default physics list, or the one specified by $PHYSLIST
  G4PhysListFactory f; run->SetUserInitialization(f.ReferencePhysList());
  run->SetUserInitialization(new Detector); // load detector definition

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
