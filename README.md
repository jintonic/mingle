The [v1][] tag on the tip of the [batch][] branch marks a version of [MinGLE][] that can be run both interactively and in the so-called [batch mode][], where `mingle` can execute [Geant4][] macro commands saved in a macro file (for example, [run.mac](run.mac)) without getting into any user interface.

```sh
# run mingle in batch mode
mingle run.mac
```

[v1]: https://github.com/jintonic/mingle/releases/tag/v1
[batch]: https://github.com/jintonic/mingle/tree/batch
[MinGLE]: https://github.com/jintonic/mingle
[Geant4]: https://geant4.web.cern.ch
[batch mode]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/executeProgram.html
