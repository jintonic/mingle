The [v9][] tag on the tip of the [field][] branch marks a version of [MinGLE][] that uses [G4GlobalMagFieldMessenger][] to provide macro commands in `/globalField/` to set up a uniform magnetic field throughout the detector:

~~~sh
/run/initialize
# /globalField/ appears after /run/initialize
/globalField/verbose 1
# create a B field pointing to the positive z direction
/globalField/setValue 0 0 1 tesla
~~~

[run.mac](run.mac) is fine-tuned to show the bending of mu- particles in the B-field. Run `mingle run.mac` to see the effect in the last PNG file.

[v9]: https://github.com/jintonic/mingle/releases/tag/v9
[field]: https://github.com/jintonic/mingle/tree/field
[MinGLE]: https://github.com/jintonic/mingle
[Geant4]: https://geant4.web.cern.ch
[G4GlobalMagFieldMessenger]: https://gitlab.cern.ch/geant4/geant4/-/blob/master/source/geometry/navigation/include/G4GlobalMagFieldMessenger.hh
