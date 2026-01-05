[![YouTube](https://img.shields.io/badge/You-Tube-red?style=flat)](https://www.youtube.com/playlist?list=PLw3G-vTgPrdCkTdisAL5UdUPazZdjqlpm)
[![Bilibili](https://img.shields.io/badge/B-站-blue?style=flat)](https://space.bilibili.com/610308328)
[![Shimo](https://img.shields.io/badge/石-墨-lightgrey?style=flat)](https://shimo.im/docs/HJv6Qrvpx9R9wHqP)
[![Guided Development](https://img.shields.io/badge/Guided-Development-orange?style=flat)](#guided-development)
[![Docker Image](https://img.shields.io/badge/Docker-Image-green?style=flat)](https://hub.docker.com/r/physino/geant4)

<img src="logo.png" alt="MinGLE - Mine Geant4 Learning Example" width="35%" align="right">

`MinGLE`, a Mini [Geant4][] Learning Example, uses minimal C++ coding (less than 70 lines of code) to demonstrate the usage of 10 essential [Geant4][] components step by step. It is not tied to any specific experiment or third party library, making it a clean template to start your own [Geant4][] applications.

## Prerequisites

- [Geant4][] 10.7 or above is needed to use [G4RunManagerFactory][]
- [CMake](https://cmake.org/download/) 3.16 or above is needed to compile [mingle.cc](mingle.cc) across multiple operating systems
- A not-so-old C++ compiler, e.g.
  - [Visual studio](https://visualstudio.microsoft.com/downloads/) for Windows
  - [GCC](https://gcc.gnu.org/) for Linux
  - [clang](https://clang.llvm.org/) for MacOS installed by running `xcode-select --install` in a terminal
- [Git][] (optional, but highly recommended) for code downloading and development history browsing

## Getting started

[![YouTube](https://img.shields.io/badge/You-Tube-red?style=flat)](https://youtu.be/6xqCtS38SXQ)

If you know how to use [Git][] and [CMake][] in a Linux or Mac terminal, please follow the instruction below. It also works for Windows users in a [Git Bash](https://gitforwindows.org) terminal. If you don't, please follow [this YouTube tutorial](https://youtu.be/6xqCtS38SXQ).

```sh
# download mingle git repository from GitHub to a local hard disk
git clone https://github.com/jintonic/mingle
# get into the mingle directory
cd mingle
# create a folder build/ and run cmake with default settings inside
cmake -B build
# compile mingle.cc into executable mingle
cmake --build build --config Release
# install mingle to /path/to/Geant4/bin
cmake --install build --config Release
# run mingle in batch mode with run.mac in the current folder
mingle run.mac
```

> **Note:**
- lines start with `#` are comments, they cannot be run.
- `--config Release` is primarily for Visual Studio on Windows, it can be ignored on Linux and MacOS.
- Commands are case sensitive, e.g. `-B` cannot be replaced by `-b`.
- The `cmake --install` command will install the `mingle` executable to the `bin/` directory of your Geant4 installation path (detected during the `cmake -B build` step) based on the settings in [CMakeLists.txt](CMakeLists.txt). This saves you a manual configuration step. Since a successful Geant4 installation already requires its `bin/` folder to be in your [PATH](https://en.wikipedia.org/wiki/PATH_(variable)) (usually via the [geant4.sh][post_installation] or [geant4.bat][post_installation] setup scripts), `mingle` becomes globally available immediately. You can simply type `mingle` from any directory in your terminal to start the application.

Three PNG files will be created, the first visualizes the geometry, the second shows the trajectories of the particles, and the third shows the proton flux after all detector volumes. Also created will be a [ROOT][] file `scoring.root` containing the energy deposit in the volume `Shape1` defined in [detector.tg](detector.tg).

Most operations in [run.mac](run.mac) can also be executed one by one in the Geant4 GUI. This is achieved by running `mingle` and then loading [menu.mac](menu.mac) in the launched Geant4 GUI. [menu.mac](menu.mac) creates a menu in the Geant4 GUI, items in the menu can be executed one by one upon selection.

## Guided Development

There are two primary ways to teach a complex software framework like Geant4. The first is to disassemble a finished, feature-complete application to see how it works. However, for a beginner, this "reverse engineering" often feels like trying to learn how an engine works by looking at a fully assembled car. The second way, and the one MinGLE adopts, is to evolve the code step-by-step. By building the application one component at a time, you see the specific necessity of every line of code as it is added. This "bottom-up" approach ensures that you are never overwhelmed by boilerplate, as each stage introduces exactly one new concept.

To facilitate this step-by-step journey, MinGLE utilizes two core features of the [Git][] version control system: branches and tags. Think of a branch as a living workspace dedicated to a specific topic, like [ui][] or [physics][]. It is a place where code is active and can be modified. A tag is like a "snapshot" or a "version", like [v0][]. It marks a specific moment in time when that stage was perfectly finished and tested.

In a typical Geant4 example, the source code contains hundreds of lines of boilerplate. In `MinGLE`'s guided development roadmap built with Git branches and tags,
- each branch (e.g., [ui][]) represents a learning milestone associated with a specific Geant4 component, and
- each tag (e.g., [v0][]) marks a stable, working version of that milestone:

| Milestone | Branch | Tag | New Concepts |
| :--- | :--- | :--- | :--- |
| 0 | [ui][] | [v0][] | [G4UIExecutive][], and navigate the macro command tree |
| 1 | [batch][] | [v1][] | transition from interactive exploration to automated [batch mode][] execution |
| 2 | [run][] | [v2][] | [G4RunManagerFactory][], and the lifecycle of a simulation (run, event, etc.) |
| 3 | [physics][] | [v3][] | [G4PhysListFactory][], and validated, high-level physics models |
| 4 | [detector][] | [v4][] | define detector geometry and materials using [simple syntax in text][] files |
| 5 | [vis][] | [v5][] | [G4VisExecutive][], and [render][] 3D geometry |
| 6 | [gps][] | [v6][] | control particle generation with the [General Particle Source][] |
| 7 | [scorer][] | [v7][] | use built-in [/score/][] commands to record dose, flux, etc. |
| 8 | [ntuple][] | [v8][] | [G4TScoreNtupleWriter][], and [create histograms from ntuples](drawE.py) |
| 9 | [field][] | [v9][] | [G4GlobalMagFieldMessenger][] to create uniform B-field |

[mingle.cc](mingle.cc) grows from [v0][] to [v9][] step by step, so does [menu.mac](menu.mac). [run.mac](run.mac), however, is tailored to individual milestones to better showcase features added to each milestone. [mingle.cc](mingle.cc) and [menu.mac](menu.mac) are identical in the [main][] and [field][] branches, but [run.mac](run.mac) in [main][] is more complex than [run.mac in field](https://github.com/jintonic/mingle/blob/field/run.mac).

This structure serves the following pedagogic purposes:

- **Isolation of Concepts**: By switching to a specific branch, you see only the code required for that milestone, free from the "noise" of yet-to-be-introduced components.
- **Active Experimentation**: Unlike a static code snippet, a branch is a live workspace. You can modify the code and commit your own changes to see how they affect the simulation.
- **Stable Checkpoints**: Tags provide a "correct answer". If your experiments in a branch lead to errors, you can always compare your work against the corresponding tag to find the solution.

### Navigating Development Milestones

New to [Git][]? You can explore every stage of this project directly on the GitHub website using the branch and tag selectors at the top of the file list. However, to run the code locally, please use the terminal commands below.

List existing branches and tags:
```bash
git branch -a
git tag
```
A freshly cloned repository only has one branch: `main`. The `-a` option lists both local and remote branches.

Both branches and tags allow you to inspect the code at specific points in its evolution without changing your files:
```bash
# View the main source file for the detector geometry milestone
git show v4:mingle.cc
# or
git show detector:mingle.cc
```

To see exactly what code was added to the main application between two milestones:
```bash
# See code changes between detector (v4) and vis (v5)
git diff v4 v5 mingle.cc
# or
git diff detector vis mingle.cc
```

To move your physical working directory to a specific stage to run the simulation or experiment with the code:
```bash
# Switch to the detector branch
git switch detector
```
A local branch `detector` is created based on the remote branch `detector`, and your working directory is switched to the `detector` branch.

When you are finished exploring and want to return to the complete version of the code:
```bash
# Return to the main branch
git switch main
```

If you have modified the code while exploring and try to switch branches, Git may prevent the switch to protect your work. If you want to discard changes before returning:
```bash
git restore .
git switch main
```
If you want to keep your experiments for later:
```bash
git stash
git switch main
```
Later, use `git stash pop` to bring your changes back.

[Geant4]: https://geant4.web.cern.ch
[ROOT]: https://root.cern
[Git]: https://git-scm.com
[CMake]: https://cmake.org
[post_installation]: https://geant4-userdoc.web.cern.ch/UsersGuides/InstallationGuide/html/postinstall.html
[G4RunManagerFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/mainProgram.html#g4runmanager
[G4PhysListFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/UserActions/mandatoryActions.html?highlight=physlistfac#building-physics-list-using-factory
[G4UIExecutive]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html?highlight=g4uiexecutive#how-to-select-interface-in-your-applications
[General Particle Source]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/generalParticleSource.html
[batch mode]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/executeProgram.html
[simple syntax in text]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/Geometry/geomASCII.html
[G4VisExecutive]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Visualization/visexecutable.html#how-to-realize-visualization-drivers-in-an-executable
[render]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Visualization/visualization.html
[/score/]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/commandScore.html
[G4TScoreNtupleWriter]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/hit.html#score-ntuple-writer
[G4GlobalMagFieldMessenger]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/electroMagneticField.html#creating-a-uniform-magnetic-field-with-user-commands

[ui]: https://github.com/jintonic/mingle/tree/ui
[batch]: https://github.com/jintonic/mingle/tree/batch
[run]: https://github.com/jintonic/mingle/tree/run
[physics]: https://github.com/jintonic/mingle/tree/physics
[detector]: https://github.com/jintonic/mingle/tree/detector
[gps]: https://github.com/jintonic/mingle/tree/gps
[vis]: https://github.com/jintonic/mingle/tree/vis
[scorer]: https://github.com/jintonic/mingle/tree/scorer
[ntuple]: https://github.com/jintonic/mingle/tree/ntuple
[field]: https://github.com/jintonic/mingle/tree/field
[main]: https://github.com/jintonic/mingle

[v0]: https://github.com/jintonic/mingle/releases/tag/v0
[v1]: https://github.com/jintonic/mingle/releases/tag/v1
[v2]: https://github.com/jintonic/mingle/releases/tag/v2
[v3]: https://github.com/jintonic/mingle/releases/tag/v3
[v4]: https://github.com/jintonic/mingle/releases/tag/v4
[v5]: https://github.com/jintonic/mingle/releases/tag/v5
[v6]: https://github.com/jintonic/mingle/releases/tag/v6
[v7]: https://github.com/jintonic/mingle/releases/tag/v7
[v8]: https://github.com/jintonic/mingle/releases/tag/v8
[v9]: https://github.com/jintonic/mingle/releases/tag/v9
