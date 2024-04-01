# Geant4 (>=11.2) is pre-compiled on 64-bit AlmaLinux (https://geant4.org/download)
# So we target linux/amd64 platform (https://stackoverflow.com/a/60252669/1801749)
from --platform=linux/amd64 almalinux

# install pre-compiled geant4 to /usr to avoid setting LD_LIBRARY_DATA
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
run cd /usr && sed -i -e '5,27d' -e '$d' -e 's|share|/usr/share|' README \
 && sed -i -E 's|the.{,14}Manual|https://hub.docker.com/r/physino/geant4|' README \
 && sed -i -E 's|build/.{,60}-Linux|usr|g' bin/geant4-config \
 && sed -i -E 's|build/.{,60}-Linux|usr|g' bin/geant4.sh \
 && cd /root && rm -f .*cshrc \
 && echo 'alias ls="ls --color"' >> .bashrc \ 
 && echo 'alias la="ls -A"' >> .bashrc \
 && echo 'alias ll="ls -lh"' >> .bashrc \
 && echo 'alias l="ls -Alh"' >> .bashrc \
 && echo 'echo You are running /bin/sh' >> .profile \
 && echo 'echo Type \"bash↵\" for a better UI' >> .profile

# no need to enable multi-threading in a container
env G4RUN_MANAGER_TYPE=Serial
env GEANT4_DATA_DIR=/usr/share/Geant4/data
env G4VIS_DEFAULT_DRIVER=TSG_FILE

# enable colorful shell prompt (https://superuser.com/a/367280)
env PS1="\[\e[0;32m\]\u@Geant4:\[\e[0;34m\]\w \[\e[0;31m\]\$\[\e[m\] "
env TERM="xterm-256color"
# leave a message for Docker Desktop Exec tab
# https://stackoverflow.com/a/39622593/1801749
# https://www.baeldung.com/linux/bashrc-vs-bash-profile-vs-profile
env ENV=~/.profile

# overwrite the default workdir /
workdir /root

# https://kodekloud.com/blog/keep-docker-container-running
cmd tail -12f /usr/README
