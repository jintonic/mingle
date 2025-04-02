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
	auto run = G4RunManagerFactory::CreateRunManager();

	G4ScoringManager::GetScoringManager(); // enable macro commands in /score/

	// https://geant4-forum.web.cern.ch/t/11480/3
	G4TScoreNtupleWriter<G4AnalysisManager> writer; // enable data recording
	if (run->GetRunManagerType()!=G4RunManager::sequentialRM)
		writer.SetNtupleMerging(true);// merge ntuples created in multi threads

	// load default physics list, or the one specified by $PHYSLIST
	G4PhysListFactory f; run->SetUserInitialization(f.ReferencePhysList());

	run->SetUserInitialization(new Detector); // specify detector setup

	run->SetUserInitialization(new Action); // specify user action

	G4UIExecutive* ui = nullptr; // assume batch mode
	if (argc==1) ui = new G4UIExecutive(argc, argv); // interactive mode

	auto vis = new G4VisExecutive("quiet"); vis->Initialize(); // enable visialization

	if (ui) { // interactive mode
		ui->SessionStart(); // do this after vis
		delete ui;
	} else { // batch mode
		G4String cmd = "/control/execute ";
		G4UImanager::GetUIpointer()->ApplyCommand(cmd+argv[1]); // run a macro file
	}

	delete vis; delete run; // clear up memory
	return 0;
}
