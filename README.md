Believe it or not, six lines of C++ are enough to create a [Geant4][] application that can be launched. A tag [v0][] is created for you to have a snick peek at the code:

```sh
git show v0:mingle.cc
```
```cpp
#include <G4UIExecutive.hh>
int main(int argc, char** argv)
{
  G4UIExecutive ui(argc, argv);
  ui.SessionStart();
}
```

This version of [MinGLE][] includes only one [Geant4][] component, [G4UIExecutive][], which provides a variety of user interfaces (UI) for us to pick.

A branch [ui][] is created for you to quickly switch to the stage

```sh
git switch ui
```

and compile and run it using instructions in the [Getting Started][] section.

[menu.mac](menu.mac) can be loaded in a GUI session to add menu items to the GUI. [run.mac](run.mac) can be loaded in a GUI or run in a TUI using the macro command `/control/execute run.mac`. They are used to demonstrate the usage of interactive UI, macro commands, and macro files.

[Geant4]: https://geant4.web.cern.ch
[MinGLE]: https://github.com/jintonic/mingle
[G4UIExecutive]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html?highlight=g4uiexecutive#how-to-select-interface-in-your-applications
[ui]: https://github.com/jintonic/mingle/tree/ui
[v0]: https://github.com/jintonic/mingle/releases/tag/v0
[Getting Started]: https://github.com/jintonic/mingle/tree/main?tab=readme-ov-file#getting-started
