#include <G4RunManagerFactory.hh>
#include <G4PhysListFactory.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
int main(int argc, char** argv)
{
	auto *run = G4RunManagerFactory::CreateRunManager();

	// load default physics list, or the one specified by $PHYSLIST
	G4PhysListFactory f; run->SetUserInitialization(f.ReferencePhysList());

	if (argc==1) { // interactive mode
		G4UIExecutive ui(argc, argv);
		ui.SessionStart();
	} else { // batch mode
		G4String command = "/control/execute ";
		G4UImanager::GetUIpointer()->ApplyCommand(command+argv[1]);
	}

	delete run;
}
