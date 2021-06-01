MinGLE, a Mini Geant4 Learning Example, uses minimal C++ coding to demonstrate the usage of essential Geant4 components step by step. It also serves as a starting point of writing your own Geant4 applications.

## Pre-requisition
- [Geant4](https://geant4.web.cern.ch/support/download)
- [CMake](https://cmake.org/download/)
- A not-so-old C++ compiler, e.g.
  - [Visual studio 2019](https://visualstudio.microsoft.com/downloads/) for Windows
  - [GCC](https://gcc.gnu.org/) (4.9 or above) for Linux
  - [clang](https://clang.llvm.org/) for MacOS installed by running `xcode-select --install`

## Usage

```sh
$ git clone https://github.com/jintonic/mingle.git
$ cd mingle
$ mkdir build
$ cd build
$ ccmake ..
$ make
$ ./mingle
```

## Tags

Believe it or not, less than ten lines of C++ are enough to create a Geant4 application that can be launched. A tag [minimum](https://github.com/jintonic/mingle/releases/tag/minimum) is created for you to quickly switch to it:

```sh
$ git clone https://github.com/jintonic/mingle.git
$ cd mingle
$ git checkout tags/minimum
$ cloc .
       5 text files.
       5 unique files.
       3 files ignored.

github.com/AlDanial/cloc v 1.90  T=0.01 s (264.7 files/s, 1499.9 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                              1              1              0              6
CMake                            1              3              0              6
Markdown                         1              0              0              1
-------------------------------------------------------------------------------
SUM:                             3              4              0             13
-------------------------------------------------------------------------------
```

Whenever a new Geant4 component is added on top of "minimum", a new [tag](https://github.com/jintonic/mingle/tags) is created. You can check them out one by one to see how a Geant4 application is developed from scratch.
