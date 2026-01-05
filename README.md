The [v8][] tag on the tip of the [ntuple][] branch marks a version of [MinGLE][] that uses [G4TScoreNtupleWriter][] to save important statistical parameters from a [Geant4][] simulation into [ntuples][]. Run `mingle run.mac` to generate `scoring.root`, which contains a [TTree][] ([ROOT][]'s version of [ntuples][]) object `Shape1_e` that has a leaf `Shape1_e_score`, which records the energy deposition `e` in the volume called `Shape1` (defined in [detector.tg](detector.tg)) in each event. Run the following commands to draw the energy spectrum recorded in the sensitive volume `Shape1` using [ROOT][]:

```sh
root scoring.root
root[0] .ls
TFile**		scoring.root	
 TFile*		scoring.root	
  KEY: TTree	Shape1_e;1	Shape1_e
root[1] Shape1_e->Show(0)
======> EVENT:0
 Shape1_e_eventId = 1
 Shape1_e_cell   = 0
 Shape1_e_score  = 0.0239774
root [3] Shape1_e->Draw("Shape1_e_score")
```

According to [this discussion][] in the Geant4 forum, [G4TScoreNtupleWriter][] automatically creates a [G4AnalysisManager][] instance. That's why after `/run/initialize`, a new macro command sets `/analysis/` appears in the Geant4 UI. [G4TScoreNtupleWriter][] is chosen over [G4TScoreHistFiller][] since an ntuple can be used to create a histogram with a custom binning.

A Python script [drawE.py](drawE.py) is provided to draw the energy spectrum recorded in `scoring.root` using [uproot][] and [matplotlib][] for users who are not familiar with [ROOT][].

[menu.mac](menu.mac) is extended to allow users to pick a volume using the Geant4 GUI and record the energy deposit in it.

[v8]: https://github.com/jintonic/mingle/releases/tag/v8
[ntuple]: https://github.com/jintonic/mingle/tree/ntuple
[MinGLE]: https://github.com/jintonic/mingle
[Geant4]: https://geant4.web.cern.ch
[G4TScoreNtupleWriter]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/hit.html#score-ntuple-writer
[histograms]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/commandScore.html?highlight=score#writing-scores-to-a-file
[ntuples]: https://en.wikipedia.org/wiki/Tuple
[TTree]: https://root.cern.ch/doc/master/classTTree.html
[ROOT]: https://root.cern.ch
[this discussion]: https://geant4-forum.web.cern.ch/t/11480/3
[G4AnalysisManager]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Analysis/managers.html
[G4TScoreHistFiller]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/commandScore.html#filling-1-d-histogram
[uproot]: https://uproot.readthedocs.io
[matplotlib]: https://matplotlib.org
