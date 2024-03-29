# Geant4 (>=11.2) is pre-compiled on 64-bit AlmaLinux (https://geant4.org/download)
# So we target linux/amd64 platform (https://stackoverflow.com/a/60252669/1801749)
from --platform=linux/amd64 almalinux

# install pre-compiled geant4 to /usr
run cd /usr \
 && curl -LO https://cern.ch/geant4-data/releases/lib4.11.2.p01/Linux-g++11.4.1-Alma9.tar.gz \
 && tar xf *.gz && rm -f *.gz

# install development tools
# `cmake` requires `make`, `which` is needed when run `make`
# `mesa-libGL`, `libXmu`, `expat` are needed to compile geant4 applications
# their -devel packages are needed to provide unversioned .so files
run dnf install -y gcc-c++ cmake which mesa-libGL-devel libXmu-devel expat-devel \
 && dnf clean all && rm -fr /var/cache/*

# compile and install MinGLE
run curl -LO https://github.com/jintonic/mingle/raw/main/mingle.cc \
 && curl -LO https://github.com/jintonic/mingle/raw/main/CMakeLists.txt \
 && cmake . && make install && rm -fr afs mingle* *ake* *.txt

# set up environment
run sed -i -E "s|build/.{,60}-Linux|usr|g" /usr/bin/geant4-config \
 && sed -i -E "s|build/.{,60}-Linux|usr|g" /usr/bin/geant4.sh \
 && echo 'alias ls="ls --color"' >> /root/.bashrc \ 
 && echo 'alias la="ls -A"' >> /root/.bashrc \
 && echo 'alias ll="ls -lh"' >> /root/.bashrc \
 && echo 'alias l="ls -Alh"' >> /root/.bashrc

# no need to enable multi-threading in a container
env G4RUN_MANAGER_TYPE=Serial
env GEANT4_DATA_DIR=/usr/share/Geant4/data

# enable colorful shell prompt (https://superuser.com/a/367280)
env PS1="\[\e[0;32m\]\u@Geant4:\[\e[0;34m\]\w \[\e[0;31m\]\$\[\e[m\] "
env TERM="xterm-256color"

# overwrite the default workdir /
workdir /root
