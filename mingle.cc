#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
int main(int argc, char** argv)
{
  if (argc == 1) { // interactive mode
    G4UIExecutive ui(argc, argv);
    ui.SessionStart();
  } else { // batch mode
    G4String command = "/control/execute ";
    G4UImanager::GetUIpointer()->ApplyCommand(command + argv[1]);
  }
}
