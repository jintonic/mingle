The [v5][] tag on the tip of the [vis][] branch marks a version of [MinGLE][] that uses [Geant4][] [visualization][] drivers to visualize detector geometry. Run `mingle run.mac` to generate various visualization output files. A detailed description on each visualization method is available [here](https://physino.xyz/geant4/vis/).

The visualization can also be tuned interactively. Run `mingle` to start an interactive session, and then load `menu.mac` to add a "Visualization" menu to the Geant4 UI. Select "Run" and then "Initialize" to load the detector geometry. After that, select individual items in the "Visualization" menu from top to bottom to observe the effect of each command. Note that the mouse can be used to zoom, pan, and rotate the detector geometry. All visualization drivers available can be listed by selecting "List Visualization Drivers" in the "Help" menu.

[Geant4]: https://geant4.web.cern.ch
[MinGLE]: https://github.com/jintonic/mingle
[visualization]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/visualization.html
[v5]: https://github.com/jintonic/mingle/releases/tag/v5
[vis]: https://github.com/jintonic/mingle/tree/vis
