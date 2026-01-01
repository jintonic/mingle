The [v5][] tag on the tip of the [gps branch][] marks a version of [MinGLE][] that uses the [Geant4][] general particle source ([GPS][]) to generate primary particles, from which a [Geant4][] simulation starts, as demonstrated in the following sketch:

<img src="https://github.com/jintonic/gears/blob/master/examples/output/tracks.png" style="width:100%" alt="tracks.png">

Up-to-date examples of [GPS][] are shipped together with the [Geant4][] source code on <https://gitlab.cern.ch/geant4/geant4/tree/master/examples/extended/eventgenerator/exgps/macros>.

An [outdated webpage](http://hurel.hanyang.ac.kr/Geant4/Geant4_GPS/reat.space.qinetiq.com/gps/examples/examples.html) shows distribution plots from most of these examples, which are very helpful to understand the real effects of the [GPS][] macro commands.

An ASCII version of the manual of [GPS][] macros is available [here](https://github.com/jintonic/gears/blob/master/tutorials/sources/gps.txt).

[run.mac](run.mac) in this version mimicks the Geant4 basic example [B1][], demonstrating how to shoot 210 MeV protons to the geometry and print simulation steps one by one on screen:

```sh
mingle run.mac
...
*********************************************************************************************************
* G4Track Information:   Particle = proton,   Track ID = 1,   Parent ID = 0
*********************************************************************************************************
Step#    X(mm)    Y(mm)    Z(mm) KinE(MeV)  dE(MeV) StepLeng TrackLeng  NextVolume ProcName
    0     2.39     2.95     -150       210        0        0         0    Envelope initStep
    1     2.39     2.95     -100       189     21.4       50        50      Shape1 Transportation
    2     3.23      2.6    -63.4       170     19.1     36.7      86.7      Shape1 hIoni
    3     3.43     2.51      -40       156     13.2     23.4       110    Envelope Transportation
    4     3.65     2.68    -15.9       144       12     24.1       134    Envelope hIoni
    5     4.03     3.56     13.9       127     17.1     29.8       164    Envelope hIoni
    6      4.3     3.82     26.4       119     7.86     12.5       176    Envelope hIoni
    7     4.66     4.14     38.7         0     7.64     12.3       189    Envelope protonInelastic
    :----- List of 2ndaries - #SpawnInStep=  8(Rest= 0,Along= 0,Post= 8), #SpawnTotal=  8 ---------------
    :      4.66      4.14      38.7      47.4             proton
    :      4.66      4.14      38.7      15.5             proton
    :      4.66      4.14      38.7      4.08              gamma
    :      4.66      4.14      38.7      3.11              gamma
    :      4.66      4.14      38.7      2.23            neutron
    :      4.66      4.14      38.7     0.121              gamma
    :      4.66      4.14      38.7      5.97           deuteron
    :      4.66      4.14      38.7    0.0543                C12
    :----------------------------------------------------------------- EndOf2ndaries Info ---------------
...
*********************************************************************************************************
* G4Track Information:   Particle = gamma,   Track ID = 4,   Parent ID = 1
*********************************************************************************************************
Step#    X(mm)    Y(mm)    Z(mm) KinE(MeV)  dE(MeV) StepLeng TrackLeng  NextVolume ProcName
    0     4.66     4.14     38.7      4.08        0        0         0    Envelope initStep
    1     4.37      4.2       40      4.08        0     1.34      1.34      Shape2 Transportation
    2    -8.92     6.93      100      4.08        0     61.5      62.9    Envelope Transportation
    3      -20     9.21      150      4.08        0     51.3       114       World Transportation
    4    -26.6     10.6      180      4.08        0     30.8       145  OutOfWorld Transportation
...
```

One may see the following warning message. According to [this reply](https://geant4-forum.web.cern.ch/t/a-warning-message-about-a-program-running/10328/4) on Geant4 forum, it can be safely ignored.
```
-------- WWWW ------- G4Exception-START -------- WWWW -------
*** G4Exception : Run10035
      issued by : G4TaskRunManager::InitializeEventLoop()
Event modulo is reduced to 1 (was 2) to distribute events to all threads.
*** This is just a warning message. ***
-------- WWWW -------- G4Exception-END --------- WWWW -------
```

[Geant4]: https://geant4.web.cern.ch
[MinGLE]: https://github.com/jintonic/mingle
[B1]: https://gitlab.cern.ch/geant4/geant4/-/blob/master/examples/basic/B1/src/PrimaryGeneratorAction.cc#L67
[GPS]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/generalParticleSource.html
[gps branch]: https://github.com/jintonic/mingle/tree/gps
[v5]: https://github.com/jintonic/mingle/releases/tag/v5
