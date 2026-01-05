The [v7][] tag on the tip of the [scorer][] branch marks a version of [MinGLE][] that uses [G4ScoringManager][] to record some important statistical parameters from a [Geant4][] simulation. Run `mingle run.mac` to generate one CSV file, which record numbers of protons going through detector volume `Shape1` defined in [detector.tg](detector.tg), and two PNG files, one shows only detector geometry, and the other shows dose distributions right after the detector volume `Shape2`.

[menu.mac](menu.mac) is extended to allow users to record dose deposit in a detector volume through the Geant4 GUI.

[v7]: https://github.com/jintonic/mingle/releases/tag/v7
[scorer]: https://github.com/jintonic/mingle/tree/scorer
[MinGLE]: https://github.com/MinGLE/MinGLE
[Geant4]: https://geant4.web.cern.ch
[G4ScoringManager]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/commandScore.html
