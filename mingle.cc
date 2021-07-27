#include <G4VUserDetectorConstruction.hh>
#include <G4PSEnergyDeposit.hh>
#include <G4tgbVolumeMgr.hh>
#include <G4SDManager.hh>

class Detector : public G4VUserDetectorConstruction
{
	public:
		G4VPhysicalVolume* Construct() {
			G4tgbVolumeMgr::GetInstance()->AddTextFile("detector.tg");
			return G4tgbVolumeMgr::GetInstance()->ReadAndConstructDetector();
		} ///< load detector definition from a text file "detector.tg"
		void ConstructSDandField() {
			G4MultiFunctionalDetector* d = new G4MultiFunctionalDetector("d");
			G4SDManager::GetSDMpointer()->AddNewDetector(d);
			G4VPrimitiveScorer* scorer = new G4PSEnergyDeposit("e");
			d->RegisterPrimitive(scorer);
			SetSensitiveDetector("d",d);
		} ///< make "d" volume in "detector.tg" sensitive
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#include <G4UserRunAction.hh>
#include <G4TScoreHistFiller.hh>
#include <G4TScoreNtupleWriter.hh>
#include <G4GenericAnalysisManager.hh>

class RunAction : public G4UserRunAction
{
	public:
		G4GenericAnalysisManager *fAnaMgr;
		G4TScoreHistFiller<G4GenericAnalysisManager> *fFiller;
		G4TScoreNtupleWriter<G4GenericAnalysisManager> *fWriter;

		RunAction() : G4UserRunAction() {
			fAnaMgr = G4GenericAnalysisManager::Instance();
			fAnaMgr->SetNtupleMerging(true); // merge data from multiple threads
			fFiller = new G4TScoreHistFiller<G4GenericAnalysisManager>;
			fWriter = new G4TScoreNtupleWriter<G4GenericAnalysisManager>;
		} ///< initialize analysis manager, histogram filler and ntuple writer
		~RunAction() { delete fAnaMgr; delete fFiller; delete fWriter; }

		void BeginOfRunAction(const G4Run*) {
			if (fAnaMgr->GetFileName()=="") return;
			fAnaMgr->OpenFile(fAnaMgr->GetFileName());
		} ///< open output file specified by /analysis/setFileName
		void EndOfRunAction(const G4Run*) {
			if (fAnaMgr->GetFileName()=="") return;
			fAnaMgr->Write(); fAnaMgr->CloseFile();
		} ///< write data to and close output file if it is specified
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
		void BuildForMaster() const { SetUserAction(new RunAction); }
		void Build() const {
			SetUserAction(new RunAction);
			SetUserAction(new Generator);
		}
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#include <G4RunManagerFactory.hh>
#include <G4PhysListFactory.hh>
#include <G4ScoringManager.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <G4VisManager.hh>
#include <G4UImanager.hh>

int main(int argc,char** argv)
{
	auto *run = G4RunManagerFactory::CreateRunManager();

	G4ScoringManager::GetScoringManager();

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
