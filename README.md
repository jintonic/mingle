[![YouTube](https://img.shields.io/badge/You-Tube-red?style=flat)](https://www.youtube.com/playlist?list=PLw3G-vTgPrdCkTdisAL5UdUPazZdjqlpm)
[![Bilibili](https://img.shields.io/badge/B-站-blue?style=flat)](https://space.bilibili.com/610308328)
[![Shimo](https://img.shields.io/badge/石-墨-lightgrey?style=flat)](https://shimo.im/docs/HJv6Qrvpx9R9wHqP)
[![Guided Development](https://img.shields.io/badge/Guided-Development-orange?style=flat)](#guided-development)
[![Docker Image](https://img.shields.io/badge/Docker-Image-green?style=flat)](https://hub.docker.com/r/physino/geant4)

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

| Stage | Milestone | Branch | Tag | Focus |
| :--- | :--- | :--- | :--- | :--- |
| 0 | [user interface][] | [ui][] | [v0][] | interact with Geant4 via TUI/GUI and navigate the macro command tree |
| 1 | [batch execution][] | [batch][] | [v1][] | transition from interactive exploration to automated batch-mode execution |
| 2 | [run manager][] | [run][] | [v2][] | initialize the simulation kernel and understand the lifecycle of a simulation (run, event, etc.) |
| 3 | [physics list][] | [physics][] | [v3][] | use `G4PhysListFactory` to select validated, high-level physics models |
| 4 | [detector geometry][] | [detector][] | [v4][] | define detector geometry and materials using simple syntax in text files |
| 5 | [primary particle][] | [gps][] | [v5][] | control particle generation dynamically with the General Particle Source |
| 6 | [visualization][] | [vis][] | [v6][] | implement `G4VisExecutive` to render 3D geometry and trajectories |
| 7 | [histogram generation][] | [score][] | [v7][] | use built-in command-line mesh scorers to generate histograms of dose, flux, etc. |
| 8 | [ntuple generation][] | [ntuple][] | [v8][] | use `G4AnalysisManager` to save ntuples in ROOT or CSV format |
| 9 | [magnetic field][] | [field][] | [v9][] | add electromagnetic field managers to simulate particle deflection |

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

### User Interface

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

This version of `MinGLE` includes only one [Geant4][] component, [G4UIExecutive][], which [provides a variety of user interfaces (UI) for us to pick](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html#how-to-select-interface-in-your-applications).

A branch [ui][] is created for you to quickly switch to the stage

```sh
git switch ui
```

and compile and run it using instructions in the [Getting Started](#getting-started) section.

[menu.mac](menu.mac) can be loaded in a GUI session to add menu items to the GUI. [run.mac](run.mac) can be loaded in a GUI or run in a TUI using the macro command `/control/execute run.mac`. They are used to demonstrate the usage of interactive UI, macro commands, and macro files.

### Batch Execution

The [v1][] tag on the tip of the [batch][] branch marks a version of `mingle` that can be run both interactively and in the so-called batch mode, where `mingle` can execute [Geant4][] macro commands saved in a macro file (for example, [run.mac](run.mac)) without getting into any user interface.

```sh
# run mingle in batch mode
mingle run.mac
```

### Run Manager

The tag [v2][] on the tip of the [run][] branch marks a version of `mingle` that creates a [Geant4][] [Run][] manager using [G4RunManagerFactory][] that is only introduced until [Geant4][] 10.7, which allows the switching in between various [Run][] managers using an environment variable `G4RUN_MANAGER_TYPE`:

```sh
# run mingle in serial mode
G4RUN_MANAGER_TYPE=Serial mingle
Environment variable "G4RUN_MANAGER_TYPE" enabled with value == Serial. Overriding G4RunManager type...
**************************************************************
 Geant4 version Name: geant4-1i-0j-patch-0k [MT]   (date)
```
```sh
# run mingle in multithreaded mode
$ G4RUN_MANAGER_TYPE=MT mingle
**************************************************************
 Geant4 version Name: geant4-1i-0j-patch-0k [MT]   (date)
  << in Multi-threaded mode >>
```

Many new macro commands (`/tracking/`, `/geometry/`, `/process/`, `/particle/`, `/run/`, `/event/`, `/cuts/`, `/random/`) become available with the creation of the run manager. However, most of them are merely space-holders that will become useful when their corresponding components are implemented.

A few macro commands do become useful in this stage, for example, `/units/list` now can print out the list of units used by Geant4. It is added to [menu.mac](menu.mac) as an item in the "Help" menu. Many verbosity control commands are added to the "Verbosity" menu as well. `/random/setSeeds` is added to [run.mac](run.mac) to initialize the random number generator with an integer seed stream.

### Physics List

The tag [v3][] on the tip of the [physics][] branch marks a version of `MinGLE` that creates a physics [list][] using [G4PhysListFactory][], which allows the switching among various physics [list][]s using an environment variable `PHYSLIST`:

```sh
PHYSLIST=FTFP_BERT_EMV mingle
**************************************************************
 Geant4 version Name: geant4-1i-0j-patch-0k [MT]   (date)
 ...
**************************************************************
G4PhysListFactory::GetReferencePhysList <FTFP_BERT_EMV>  EMoption= 1
<<< Geant4 Physics List simulation engine: FTFP_BERT
<<< Reference Physics List FTFP_BERT_EMV is built
```

Two new macro command sets (`/physics_lists/`, `/material/`) become available with the creation of the physics list. `/particle/list` now can really be used to list all particles available in Geant4 and are added to [menu.mac](menu.mac) together with `/material/nist/listMaterials` as items in the "Help" menu. More sub commands are added to `/process/` and `/particle/` as well.

### Detector Definition

The tag [v4][] on the tip of the [detector][] branch marks a version of `MinGLE` that can [load detector definition from a text file][tg], [detector.tg](detector.tg), using a [simple syntax introduced since Geant4.9.2][tg], where a cone made of A-150 tissue-equivalent plastic and a trapezoid made of bone are placed in a box made of water:

```
:volu World BOX 120 120 180 G4_AIR
:volu Envelope BOX 100 100 150 G4_WATER
:volu Shape1 CONS 0 20 0 40 30 0 360 G4_A-150_TISSUE
:volu Shape2 TRD 60 60 50 80 30 G4_BONE_COMPACT_ICRU

:rotm r000 0 0 0
:place Envelope 1 World  r000 0  0   0
:place Shape1 1 Envelope r000 0  20 -70
:place Shape2 2 Envelope r000 0 -10  70
```

The same definition in Geant4 basic example [B1][] requires more than 100 lines of C++ in two files. In addition to its simplicity, the text geometry definition can be modified and loaded without recompiling the C++ code. More importantly, the separation of detector definition from the C++ program makes the latter more universal as it is not associated with any specific detector. `MinGLE` hence can be used for the simulation of any detector without modifying and compiling the C++ code. The last advantage of using the [text geometry definition][tg] instead of C++ is to keep the length of the C++ program unchanged no matter how complicated the detector definition becomes.

To use the geometry defined in [detector.tg](detector.tg), the file must be placed in the directory where `mingle` is executed. Otherwise, Geant4 will complain that `detector.tg` file does not exist. For example,

```sh
$ cd /to/a/path/without/detector.tg
$ mingle
PreInit> /run/initialize
-------- EEEE ------- G4Exception-START -------- EEEE -------
*** G4Exception : InvalidInput
      issued by : G4tgrFileIn::OpenNewFile()
Input file does not exist: detector.tg
*** Fatal Exception *** core dump ***
 **** Track information is not available at this moment
 **** Step information is not available at this moment
-------- EEEE -------- G4Exception-END --------- EEEE -------
*** G4Exception: Aborting execution ***
Abort trap: 6
```

With the detector defined, one can finally initialize a run using the `/run/initialize` macro command, which will load the detector geometry and initialize physics processes. After that, `/geometry/test/run` can be used to check if there is any overlapping between detector volumes, and `/process/list` can be used to list all initialized physics processes. [run.mac](run.mac) shows how to use these macro commands, which can be called in batch mode:

```sh
mingle run.mac
```

By default, `/run/initialize` prints a ton of information on the screen, which may be overwhelming for a beginner. To avoid that, the following two commands are added to [run.mac](run.mac) to disable the verbose output from electromagnetic and hadronic physics processes:

```
/process/em/verbose 0
/process/had/verbose 0
```

On the other hand, `/run/verbose 2` is added to [run.mac](run.mac) to print in detail how a run is done on screen:

```
# show in detail how a run is done
/run/verbose 2
# load detector definition and physics processes
/run/initialize
userDetector->Construct() start.
World is registered to the default region.
physicsList->Construct() start.
...
physicsList->CheckParticleList() start.
physicsList->setCut() start.
# check overlapping between detector volumes
/geometry/test/run
Running geometry overlaps check...
...
Geometry overlaps check completed !
# print physics processes
/process/list
     Transportation,   GammaGeneralProc,   msc,   eIoni
     ...
G4 kernel has come to Quit state.
UserDetectorConstruction deleted 0xaa6e06de0
UserPhysicsList deleted 0x109c777d0
UserActionInitialization deleted 0x0
UserWorkerInitialization deleted 0x0
UserWorkerThreadInitialization deleted 0x0
UserRunAction deleted.
UserPrimaryGenerator deleted.
RunManager is deleting RunManagerKernel.
G4SDManager deleted.
EventManager deleted.
Units table cleared.
TransportationManager deleted.
Total navigation history collections cleaned: 2
G4RNGHelper object is deleted.
================== Deleting memory pools ===================
Pool ID '20G4NavigationLevelRep', size : 0.00288 MB
Pool ID '24G4ReferenceCountedHandleIvE', size : 0.000961 MB
Pool ID '15G4CountedObjectIvE', size : 0.000961 MB
Number of memory pools allocated: 3; of which, static: 0
Dynamic pools deleted: 3 / Total memory freed: 0.0048 MB
============================================================
G4Allocator objects are deleted.
UImanager deleted.
StateManager deleted.
RunManagerKernel is deleted. Good bye :)
RunManager is deleted.
```
which shows clearly when each component is constructed and then deleted.

By default, Geant4 runs in multi-thread mode. Each thread prints its own output. To avoid intertwined outputs from threads, `/control/cout/useBuffer` is added to [run.mac](run.mac) to group the output from each thread into a buffer and print out one buffer at a time. However, this is still not ideal as a lot of information is duplicated in each thread buffer. The cleanest output can only be obtained by running `mingle` in serial mode as shown in section [Run Manager](#run-manager).

[menu.mac](menu.mac) is expanded in this stage to allow users to execute individual commands in [run.mac](run.mac) in a Geant4 GUI.

A new macro command set `/physics_engine/` appears after `/run/initialize` is called. It allows users to set energy and time limits for neutron tracking.

[Geant4]: https://geant4.web.cern.ch
[Git]: https://git-scm.com
[CMake]: https://cmake.org
[post_installation]: https://geant4-userdoc.web.cern.ch/UsersGuides/InstallationGuide/html/postinstall.html
[G4RunManagerFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/mainProgram.html#g4runmanager
[G4UIExecutive]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/graphicalUserInterface.html?highlight=g4uiexecutive#how-to-select-interface-in-your-applications
[Run]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Fundamentals/run.html
[list]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/UserActions/mandatoryActions.html?#physics-lists
[G4PhysListFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/UserActions/mandatoryActions.html?#building-physics-list-using-factory
[tg]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/Geometry/geomASCII.html
[B1]: https://gitlab.cern.ch/geant4/geant4/-/tree/master/examples/basic/B1

[user interface]: https://github.com/jintonic/mingle?tab=readme-ov-file#user-interface
[batch execution]: https://github.com/jintonic/mingle?tab=readme-ov-file#batch-execution
[run manager]: https://github.com/jintonic/mingle?tab=readme-ov-file#run-manager
[physics list]: https://github.com/jintonic/mingle?tab=readme-ov-file#physics-list
[detector geometry]: https://github.com/jintonic/mingle?tab=readme-ov-file#detector-geometry
[primary particle]: https://github.com/jintonic/mingle?tab=readme-ov-file#primary-particle
[visualization]: https://github.com/jintonic/mingle?tab=readme-ov-file#visualization
[histogram generation]: https://github.com/jintonic/mingle?tab=readme-ov-file#histogram-generation
[ntuple generation]: https://github.com/jintonic/mingle?tab=readme-ov-file#ntuple-generation
[magnetic field]: https://github.com/jintonic/mingle?tab=readme-ov-file#magnetic-field

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
