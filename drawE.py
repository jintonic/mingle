#!/usr/bin/env python3
# open a root file using uproot
import uproot
f = uproot.open('scoring.root')
# check what's in the file
f.keys()

# get ROOT tree (https://root.cern/manual/trees/) named 'Shape1_e'
t = f['Shape1_e']
# list branches in the tree
t.keys()
# get branch 'Shape1_e_score'
b = t['Shape1_e_score']
# get values in the branch as an awkward array
e = b.array()

# draw energy (e) distribution
import matplotlib.pyplot as p
p.hist(e, bins=100)
p.xlabel('Energy deposition in Shape1 [MeV]')
p.ylabel('Entries/(6 keV)')
p.title('Histogram Generated from Ntuple')
p.text(0.038, 810, r'Full-absorption peak $\rightarrow$')
p.text(0, 410, r'Back-scattering peak')
p.grid(True)

# show canvas
p.show()
