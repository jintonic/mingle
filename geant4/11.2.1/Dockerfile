# Geant4 (>=11.2) is pre-compiled on 64-bit AlmaLinux (https://geant4.org/download)
# So we target linux/amd64 platform (https://stackoverflow.com/a/60252669/1801749)
from --platform=linux/amd64 almalinux

# install pre-compiled Geant4 in /usr to avoid setting LD_LIBRARY_PATH
run cd /usr \
 && curl -LO https://cern.ch/geant4-data/releases/lib4.11.2.p01/Linux-g++11.4.1-Alma9.tar.gz \
 && tar xf *.gz && rm -f *.gz /root/.*cshrc && ln -sf /geant4 /root \
 && sed -i -E 's|build/.{,74}Ge|ge|g' bin/geant4-config \
 && sed -i -E 's|build/.{,74}Ge|ge|g' bin/geant4.sh \
 && echo 'alias ls="ls --color"' >> /etc/bashrc \ 
 && echo 'alias la="ls -A"' >> /etc/bashrc \
 && echo 'alias ll="ls -lh"' >> /etc/bashrc \
 && echo 'alias l="ls -Alh"' >> /etc/bashrc \

# compile and install MinGLE as a test of the Geant4 installation
# `cmake` requires `make`, `which` is needed when run `make`
# `mesa-libGL`, `libXmu`, `expat` are needed to compile Geant4 applications
# their -devel packages are needed to provide unversioned .so files
run <<EOT sh
 dnf install -y gcc-c++ cmake which mesa-libGL-devel libXmu-devel expat-devel
 dnf clean all && rm -fr /var/cache/* 
 curl -LO https://github.com/jintonic/mingle/raw/main/CMakeLists.txt
 curl -LO https://github.com/jintonic/mingle/raw/main/mingle.cc
 cmake . && make install && rm -fr afs mingle* *ake* *.txt
EOT

# no need to enable multi-threading in a container
env G4RUN_MANAGER_TYPE=Serial
env GEANT4_DATA_DIR=/geant4/data
env G4VIS_DEFAULT_DRIVER=VRML2FILE

# enable colorful shell prompt (https://superuser.com/a/367280)
env PS1="\[\e[0;32m\]\u@AlmaLinux:\[\e[0;34m\]\w \[\e[0;31m\]\$\[\e[m\] "
env TERM="xterm-256color"
# leave a message for Docker Desktop Exec tab
# https://stackoverflow.com/a/39622593/1801749
# https://www.baeldung.com/linux/bashrc-vs-bash-profile-vs-profile
env ENV=~/.profile

# overwrite the default workdir /
workdir /geant4
