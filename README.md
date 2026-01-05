The tag [v4][] on the tip of the [detector][] branch marks a version of [MinGLE][] that can load detector definition from a text file [detector.tg](detector.tg), using a [simple syntax introduced since Geant4.9.2][tg], where a cone made of A-150 tissue-equivalent plastic and a trapezoid made of bone are placed in a box made of water:

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
cd /to/a/path/without/detector.tg
mingle
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

By default, Geant4 runs in multi-thread mode. Each thread prints its own output. To avoid intertwined outputs from threads, `/control/cout/useBuffer` is added to [run.mac](run.mac) to group the output from each thread into a buffer and print out one buffer at a time. However, this is still not ideal as a lot of information is duplicated in each thread buffer. The cleanest output can only be obtained by running `mingle` in serial mode as shown in branch [run][].

[menu.mac](menu.mac) is expanded in this stage to allow users to execute individual commands in [run.mac](run.mac) in a Geant4 GUI.

A new macro command set `/physics_engine/` appears after `/run/initialize` is called. It allows users to set energy and time limits for neutron tracking.

[v4]: https://github.com/jintonic/mingle/releases/tag/v4
[detector]: https://github.com/jintonic/mingle/tree/detector
[MinGLE]: https://github.com/jintonic/mingle
[Geant4]: https://geant4.web.cern.ch
[tg]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/Geometry/geomASCII.html
[B1]: https://gitlab.cern.ch/geant4/geant4/-/tree/master/examples/basic/B1
[run]: https://github.com/jintonic/mingle/tree/run
