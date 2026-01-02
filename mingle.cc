#include <G4RunManagerFactory.hh>
#include <G4PhysListFactory.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
int main(int argc, char** argv)
{
  auto run = G4RunManagerFactory::CreateRunManager();
  // load default physics list, or the one specified by $PHYSLIST
  G4PhysListFactory f; run->SetUserInitialization(f.ReferencePhysList());

  if (argc == 1) { // start an interactive UI session
    G4UIExecutive ui(argc, argv);
    ui.SessionStart();
  } else { // run a macro file in batch mode
    G4String cmd = "/control/execute ", macroFile = argv[1];
    G4UImanager::GetUIpointer()->ApplyCommand(cmd + macroFile);
  }

  delete run;
}
