[![YouTube](https://img.shields.io/badge/You-Tube-red?style=flat)](https://www.youtube.com/playlist?list=PLw3G-vTgPrdCkTdisAL5UdUPazZdjqlpm)
[![bilibili](https://img.shields.io/badge/B-站-blue?style=flat)](https://space.bilibili.com/610308328)
[![shimo](https://img.shields.io/badge/石-墨-lightgrey?style=flat)](https://shimo.im/docs/HJv6Qrvpx9R9wHqP)
[![tags](https://img.shields.io/badge/Development-History-orange?style=flat)](#tags)
[![Docker image](https://img.shields.io/badge/Docker-image-green?style=flat)](https://hub.docker.com/r/physino/geant4)

`MinGLE`, a Mini [Geant4][] Learning Example, uses minimal C++ coding (60 lines of code) to demonstrate the usage of essential [Geant4][] components step by step. It is not tied to any specific experiment or third party library, which makes it a clean starting point of writing your own [Geant4][] applications.

## Prerequisites
- [Geant4][] 10.7 or above is needed to use [G4RunManagerFactory][]
- [CMake](https://cmake.org/download/) 3.16 or above is needed to compile [mingle.cc](mingle.cc) across multiple operating systems
- A not-so-old C++ compiler, e.g.
  - [Visual studio 2019](https://visualstudio.microsoft.com/downloads/) for Windows
  - [GCC](https://gcc.gnu.org/) (4.9 or above) for Linux
  - [clang](https://clang.llvm.org/) for MacOS installed by running `xcode-select --install` in a terminal
- [Git][] (optional, but highly recommended) for package downloading and development history browsing

## Getting started
[![YouTube](https://img.shields.io/badge/You-Tube-red?style=flat)](https://youtu.be/6xqCtS38SXQ)

If you know how to use [Git][] in a Linux or MacOS terminal, please follow the instruction below. If you don't, or use Windows, please follow [this YouTube tutorial](https://youtu.be/6xqCtS38SXQ).

```sh
# download mingle git repository from github to a local hard disk
git clone https://github.com/jintonic/mingle
# get into the mingle directory
cd mingle
# create a folder build/ and run cmake with default settings inside
cmake -B build
# compile mingle.cc on Linux or Mac
make -C build
# on Windows, please use the following in Git Bash terminal instead
cmake --build build --config Release
# run the generated executable (mingle) interactively in the current directory (./)
# or ./mingle.exe in a Git Bash terminal on Windows
./mingle
# or run mingle in TUI even if GUI is enabled in compilation
G4UI_USE_TCSH=1 ./mingle

Available UI session types: [ Qt, GAG, tcsh, csh ]
PreInit> ls
Command directory path : /
 Sub-directories :
   /control/   UI control commands.
   /units/   Available units.
   /gui/   UI interactors commands.
 Commands :
PreInit> cd /units/
PreInit> ls
Command directory path : /units/

Guidance :
Available units.

 Sub-directories :
 Commands :
   list * full list of available units.
PreInit> help list

Command /units/list
Guidance :
full list of available units.

PreInit> exit
```

Note that lines start with '#' are comments, they cannot be run.

## Tags

Whenever a new [Geant4][] component is added to `MinGLE`, a new [tag](https://github.com/jintonic/mingle/tags) is created. You can check them one by one to see how a [Geant4][] application is developed step by step from scratch using the `git show` command:

```sh
git show <tag>
```

### UI

Believe it or not, six lines of C++ are enough to create a [Geant4][] application that can be launched. A tag [ui](https://github.com/jintonic/mingle/releases/tag/ui) is created for you to quickly switch to it:

```sh
git clone https://github.com/jintonic/mingle
cd mingle
# git show <tag>:<file>
git show ui:mingle.cc
```
```cpp
#include <G4UIExecutive.hh>

int main(int argc,char** argv)
{
  G4UIExecutive ui(argc, argv);
  ui.SessionStart();
}
```

This version of `MinGLE` includes only one [Geant4][] component, [G4UIExecutive][], which [provides a variety of user interfaces (UI) for us to pick](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html#how-to-select-interface-in-your-applications).

We can save this version of `MinGLE` to current working folder, compile and run it:

```sh
# save (>) mingle.cc in its minimum stage to mingle.cc in current working folder
git show minimum:mingle.cc > mingle.cc
cmake -B build
make -C build
./mingle
Available UI session types: [ tcsh, csh ]
PreInit> exit
```
Use `git checkout -- mingle.cc` to get back to the latest [mingle.cc](mingle.cc).


[Geant4]: https://geant4.web.cern.ch
[Git]: https://git-scm.com
[G4RunManagerFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/mainProgram.html#g4runmanager
[G4UIExecutive]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html?highlight=g4uiexecutive#how-to-select-interface-in-your-applications
