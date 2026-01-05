The tag [v2][] on the tip of the [run branch][] marks a version of [MinGLE][] that creates a [Geant4][] [run][] manager using [G4RunManagerFactory][] that is only introduced until [Geant4][] 10.7, which allows the switching in between various [run][] managers using an environment variable `G4RUN_MANAGER_TYPE`:

```sh
# run mingle in serial mode
G4RUN_MANAGER_TYPE=Serial mingle
Environment variable "G4RUN_MANAGER_TYPE" enabled with value == Serial. Overriding G4RunManager type...
**************************************************************
 Geant4 version Name: geant4-1i-0j-patch-0k [MT]   (date)
```
```sh
# by default, mingle runs in multi-threaded mode
mingle
**************************************************************
 Geant4 version Name: geant4-1i-0j-patch-0k [MT]   (date)
  << in Multi-threaded mode >>
```

Many new macro commands (`/tracking/`, `/geometry/`, `/process/`, `/particle/`, `/run/`, `/event/`, `/cuts/`, `/random/`) become available with the creation of the run manager. However, most of them are merely space-holders that will become useful when their corresponding components are implemented.

A few macro commands do become useful in this stage, for example, `/units/list` now can print out the list of units used by Geant4. It is added to [menu.mac](menu.mac) as an item in the "Help" menu. Many verbosity control commands are added to the "Verbosity" menu as well. `/random/setSeeds` is added to [run.mac](run.mac) to initialize the random number generator with an integer seed stream.

[v2]: https://github.com/jintonic/mingle/releases/tag/v2
[run branch]: https://github.com/jintonic/mingle/tree/run
[MinGLE]: https://github.com/jintonic/mingle
[Geant4]: https://geant4.web.cern.ch
[G4RunManagerFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/mainProgram.html#g4runmanager
[run]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Fundamentals/run.html
