The tag [v3][] on the tip of the [physics][] branch marks a version of [MinGLE][] that creates a physics [list][] using [G4PhysListFactory][], which allows the switching among various physics [list][]s using an environment variable `PHYSLIST`:

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

Two new macro command sets (`/physics_lists/`, `/material/`) become available with the creation of the physics list. `/particle/list` now can really be used to list all particles available in Geant4 and is added to [menu.mac](menu.mac) together with `/material/nist/listMaterials` as items in the "Help" menu. More sub commands become available in `/process/` and `/particle/` as well.

[v3]: https://github.com/jintonic/mingle/releases/tag/v3
[physics]: https://github.com/jintonic/mingle/tree/physics
[MinGLE]: https://github.com/jintonic/mingle
[list]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/UserActions/mandatoryActions.html?#physics-lists
[G4PhysListFactory]: https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/UserActions/mandatoryActions.html?#building-physics-list-using-factory
