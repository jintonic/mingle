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
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4GeneralParticleSource.hh>

class Generator : public G4VUserPrimaryGeneratorAction
{
	private:
		G4GeneralParticleSource* fGPS;
	public:
		Generator() : G4VUserPrimaryGeneratorAction() {
			fGPS = new G4GeneralParticleSource; }
		~Generator() { delete fGPS; }
		void GeneratePrimaries(G4Event *evt) { fGPS->GeneratePrimaryVertex(evt); }
};
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <G4VUserActionInitialization.hh>

class Action : public G4VUserActionInitialization
{
	public:
		void Build() const { SetUserAction(new Generator); }
};
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <G4TScoreNtupleWriter.hh>
#include <G4RunManagerFactory.hh>
#include <G4PhysListFactory.hh>
#include <G4AnalysisManager.hh>
#include <G4ScoringManager.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <G4VisManager.hh>
#include <G4UImanager.hh>

int main(int argc,char** argv)
{
	auto *run = G4RunManagerFactory::CreateRunManager();

	G4ScoringManager::GetScoringManager(); // enable macro commands in /score/

	// https://geant4-forum.web.cern.ch/t/11480/3
	G4TScoreNtupleWriter<G4AnalysisManager> writer;
	writer.SetNtupleMerging(true); // merge ntuples created in different threads

	G4PhysListFactory factory;
	run->SetUserInitialization(factory.ReferencePhysList());

	run->SetUserInitialization(new Detector);

	run->SetUserInitialization(new Action);

	G4VisManager *vis = new G4VisExecutive("quiet"); vis->Initialize();

	if (argc==1) { // interactive mode
		G4UIExecutive ui(argc, argv);
		ui.SessionStart();
	} else { // batch mode
		G4String command = "/control/execute ";
		G4UImanager::GetUIpointer()->ApplyCommand(command+argv[1]);
	}

	delete vis; delete run;
}
