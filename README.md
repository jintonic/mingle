MinGLE, a Mini [Geant4][] Learning Example, uses minimal C++ coding to demonstrate the usage of essential [Geant4][] components step by step. It also serves as a starting point of writing your own [Geant4][] applications.

## Prerequisites
- [Geant4][] 10.7 or above
- [CMake](https://cmake.org/download/)
- A not-so-old C++ compiler, e.g.
  - [Visual studio 2019](https://visualstudio.microsoft.com/downloads/) for Windows
  - [GCC](https://gcc.gnu.org/) (4.9 or above) for Linux
  - [clang](https://clang.llvm.org/) for MacOS installed by running `xcode-select --install` in a terminal

## Usage

```sh
# download mingle git repository from github to a local hard disk
$ git clone https://github.com/jintonic/mingle.git
# get into the mingle directory
$ cd mingle
# create a subdirectory called 'build'
$ mkdir build
# get into the build directory
$ cd build
# run cmake text-based user interface (TUI)
$ ccmake ..
# compile mingle.cc
$ make
# run the generated executable (mingle) interactively in the current directory (./)
$ ./mingle
# go to the parent directory
$ cd ..
# run mingle in TUI even if there is GUI
$ G4UI_USE_TCSH=1 ./build/mingle
Available UI session types: [ Qt, GAG, tcsh, csh ]
PreInit> ls
Command directory path : /
 Sub-directories :
   /control/   UI control commands.
   /units/   Available units.
   /profiler/   Profiler controls.
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
$
```

Note that the '\$' sign represents the [command prompt](https://en.wikipedia.org/wiki/Command-line_interface#Command_prompt), not part of the commends. Lines start with '#' are comments, they cannot be run.

## Tags

### Minimum
Believe it or not, less than ten lines of C++ are enough to create a [Geant4][] application that can be launched. A tag [minimum](https://github.com/jintonic/mingle/releases/tag/minimum) is created for you to quickly switch to it:

```sh
$ git clone https://github.com/jintonic/mingle.git
$ cd mingle
# checkout the minimum stage of the project for inspection
$ git checkout tags/minimum
# use cloc (count lines of code) to count lines of C++ code in mingle.cc
$ cloc mingle.cc
       1 text files.
       1 unique files.
       0 files ignored.

github.com/AlDanial/cloc v 1.90  T=0.01 s (264.7 files/s, 1499.9 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                              1              1              0              6
-------------------------------------------------------------------------------

# switch back to the latest mingle
$ git checkout -
```

Whenever a new [Geant4][] component is added on top of "minimum", a new [tag](https://github.com/jintonic/mingle/tags) is created. You can check them out one by one to see how a [Geant4][] application is developed step by step from scratch.

### Batch
The [batch](https://github.com/jintonic/mingle/releases/tag/batch) tag marks a version of `mingle` that can be run both interactively and in the so-called batch mode, where `mingle` can execute [Geant4][] commands saved in a macro file (for example, [run.mac](run.mac)) without getting into any user interface.

```sh
# run mingle in batch mode
$ ./build/mingle run.mac
```

[Geant4]: https://geant4.web.cern.ch
