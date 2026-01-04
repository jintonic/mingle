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
p.xlabel('Energy deposition in Shape1 (a cut cone) [MeV]')
p.ylabel('Entries/(1.5 MeV)')
p.title('Histogram Generated from Ntuple')
p.text(35, 220, r'$\leftarrow$ due to protons passing through both')
p.text(43, 205, r'front and back surfaces of the cut cone')
p.grid(True)

# show canvas
p.show()
