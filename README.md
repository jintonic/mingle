The [v5][] tag on the tip of the [vis][] branch marks a version of [MinGLE][] that uses [Geant4][] [visualization][] drivers to visualize detector geometry. Run `mingle run.mac` to generate various visualization output files. A detailed description on each visualization method is available [here](https://physino.xyz/geant4/vis/).

The visualization can also be tuned interactively. Run `mingle` to start a Geant4 GUI, and then load `menu.mac` to add a "Visualization" menu to the GUI. Select "Run" and then "Initialize" to load the detector geometry. After that, select individual items in the "Visualization" menu from top to bottom to observe the effect of each command. Note that the mouse can be used to zoom, pan, and rotate the detector geometry. All visualization drivers available can be listed by selecting "List Visualization Drivers" in the "Help" menu.

In [mingle.cc](mingle.cc), `ui` is created as a pointer instead of a reference to [G4UIExecutive][] so that the visualization can be enabled between the UI creation and session start. This is required in Geant4.11 and later to allow [automatic visualization driver selection](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Visualization/commandcontrol.html#choosing-a-graphics-viewer-vis-open-command).

A new macro command set `/param/` shows up after `/run/initialize`. It is used for fast simulation (or [parameterization][]) control and is beyond the scope of [MinGLE][].

[v5]: https://github.com/jintonic/mingle/releases/tag/v5
[vis]: https://github.com/jintonic/mingle/tree/vis
[MinGLE]: https://github.com/jintonic/mingle
[Geant4]: https://geant4.web.cern.ch
[visualization]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/visualization.html
[G4UIExecutive]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html#how-to-select-interface-in-your-applications
[parameterization]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/TrackingAndPhysics/physicsProcess.html#parameterisation
