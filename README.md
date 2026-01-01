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
# download mingle git repository from github to a local hard disk
git clone https://github.com/jintonic/mingle
# get into the mingle directory
cd mingle
# create a folder build/ and run cmake with default settings inside
cmake -B build
# compile mingle.cc into executable mingle
cmake --build build --config Release
# install mingle to /path/to/Geant4/bin
cmake --install build --config Release
# run mingle interactively in the current folder
mingle
```

> **Note:**
- lines start with `#` are comments, they cannot be run.
- `--config Release` is primarily for Windows/Visual Studio, it can be ignored on Linux and MacOS.
- Commands are case sensitive, e.g. `-B` cannot be replaced by `-b`.
- The `cmake --install` command will install the `mingle` executable to the `bin/` directory of your Geant4 installation path (detected during the `cmake -B build` step) based on the settings in [CMakeLists.txt](CMakeLists.txt). This saves you a manual configuration step. Since a successful Geant4 installation already requires its `bin/` folder to be in your [PATH](https://en.wikipedia.org/wiki/PATH_(variable)) (usually via the [geant4.sh][post_installation] or [geant4.bat][post_installation] setup scripts), `mingle` becomes globally available immediately. You can simply type `mingle` from any directory in your terminal to start the application.

## Guided Development

There are two primary ways to teach a complex software framework like Geant4. The first is to disassemble a finished, feature-complete application to see how it works. However, for a beginner, this "reverse engineering" often feels like trying to learn how an engine works by looking at a fully assembled car. The second way, and the one MinGLE adopts, is to evolve the code step-by-step. By building the application one component at a time, you see the specific necessity of every line of code as it is added. This "bottom-up" approach ensures that you are never overwhelmed by boilerplate, as each stage introduces exactly one new concept.

To facilitate this step-by-step journey, MinGLE utilizes two core features of the [Git][] version control system: branches and tags. Think of a branch as a living workspace dedicated to a specific topic, like [ui][] or [physics][]. It is a place where code is active and can be modified. A tag is like a high-resolution "snapshot" or a "version", like [v0][]. It marks a specific moment in time when that stage was perfectly finished and tested.

In a typical Geant4 example, the source code contains hundreds of lines of boilerplate. In `MinGLE`'s guided development roadmap built with Git branches and tags,
- each branch (e.g., [ui][]) represents a learning milestone associated with a specific Geant4 component, and
- each tag (e.g., [v0][]) marks a stable, working version of that milestone:

| Milestone | Branch | Tag | New Concepts |
| :--- | :--- | :--- | :--- |
| 0 | [ui][] | [v0][] | [G4UIExecutive][], and navigate the macro command tree |
| 1 | [batch][] | [v1][] | transition from interactive exploration to automated batch-mode execution |
| 2 | [run][] | [v2][] | [G4RunManagerFactory][], and the lifecycle of a simulation (run, event, etc.) |
| 3 | [physics][] | [v3][] | [G4PhysListFactory][], and validated, high-level physics models |
| 4 | [detector][] | [v4][] | define detector geometry and materials using simple syntax in text files |
| 5 | [gps][] | [v5][] | control particle generation with the [General Particle Source][] |
| 6 | [vis][] | [v6][] | implement `G4VisExecutive` to render 3D geometry and trajectories |
| 7 | [score][] | [v7][] | use built-in command-line mesh scorers to generate histograms of dose, flux, etc. |
| 8 | [ntuple][] | [v8][] | use `G4AnalysisManager` to save ntuples in ROOT or CSV format |
| 9 | [field][] | [v9][] | add electromagnetic field managers to simulate particle deflection |

This structure serves the following pedagogic purposes:

- **Isolation of Concepts**: By switching to a specific branch, you see only the code required for that milestone, free from the "noise" of yet-to-be-introduced components.
- **Active Experimentation**: Unlike a static code snippet, a branch is a live workspace. You can modify the code and commit your own changes to see how they affect the simulation.
- **Stable Checkpoints**: Tags provide a "correct answer". If your experiments in a branch lead to errors, you can always compare your work against the corresponding tag to find the solution.

### Navigating Development Milestones

New to [Git][]? You can explore every stage of this project directly on the GitHub website using the branch and tag selectors at the top of the file list. However, to run the code locally, please use the terminal commands below.

Tags allow you to inspect the code at specific points in its evolution without changing your files:

```bash
# View the main source file for the detector geometry milestone
git show v4:mingle.cc
```

To see exactly what code was added to the main application between two milestones:

```bash
# See code changes between detector (v4) and primary particle (v5)
git diff v4 v5 mingle.cc
```

To move your physical working directory to a specific stage to run the simulation or experiment with the code:

```bash
# Switch to the detector branch
git switch detector
```

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
[Git]: https://git-scm.com
[CMake]: https://cmake.org
[post_installation]: https://geant4-userdoc.web.cern.ch/UsersGuides/InstallationGuide/html/postinstall.html
[G4RunManagerFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/mainProgram.html#g4runmanager
[G4PhysListFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/UserActions/mandatoryActions.html?highlight=physlistfac#building-physics-list-using-factory
[G4UIExecutive]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html?highlight=g4uiexecutive#how-to-select-interface-in-your-applications
[General Particle Source]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/generalParticleSource.html

[ui]: https://github.com/jintonic/mingle/tree/ui
[batch]: https://github.com/jintonic/mingle/tree/batch
[run]: https://github.com/jintonic/mingle/tree/run
[physics]: https://github.com/jintonic/mingle/tree/physics
[detector]: https://github.com/jintonic/mingle/tree/detector
[gps]: https://github.com/jintonic/mingle/tree/gps
[vis]: https://github.com/jintonic/mingle/tree/vis
[score]: https://github.com/jintonic/mingle/tree/score
[ntuple]: https://github.com/jintonic/mingle/tree/ntuple
[field]: https://github.com/jintonic/mingle/tree/field

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
