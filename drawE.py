#!/usr/bin/python3
# open a root file using uproot
import uproot
f = uproot.open('scoring.root')
# check what's in the file
f.keys()

# get ROOT tree (https://root.cern/manual/trees/) named 'CsI_e'
t = f['CsI_e']
# list branches in the tree
t.keys()
# get branch 'CsI_e_score'
b = t['CsI_e_score']
# get values in the branch as an awkward array
e = b.array()

# draw energy (e) distribution
import matplotlib.pyplot as p
p.hist(e, bins=100)
p.xlabel('Energy deposition in CsI [MeV]')
p.ylabel('Entries')
p.title('Linear scale')
p.text(1.63, 4020, r'Full-absorption peak $\rightarrow$')
p.grid(True)

# draw e in log scale
p.figure()
p.hist(e, bins=100, log=True)
p.xlabel('Energy deposition in CsI [MeV]')
p.ylabel('Entries')
p.title('Log scale')
p.text(1.18, 250, r'Single-escape peak $\rightarrow$')
p.text(0.63, 6.2, r'Compton continuum', color='white')
p.grid(True)

# show canvas
p.show()

