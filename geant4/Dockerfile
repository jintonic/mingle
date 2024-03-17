from --platform=linux/amd64 physino/geant4:minimal

# install minimal datasets (https://geant4-forum.web.cern.ch/t/11527/2)
run mkdir -p /usr/share/Geant4/data && cd /usr/share/Geant4/data \
 && curl -LO https://cern.ch/geant4-data/datasets/G4ENSDFSTATE.2.3.tar.gz \
 && curl -LO https://cern.ch/geant4-data/datasets/G4PhotonEvaporation.5.7.tar.gz \
 && curl -LO https://cern.ch/geant4-data/datasets/G4EMLOW.8.5.tar.gz \
 && curl -LO https://cern.ch/geant4-data/datasets/G4PARTICLEXS.4.0.tar.gz \
 && tar xf *EN* && tar xf *EM* && tar xf *Ph* && tar xf *PA* && rm -f *.gz 

# install command-line tools
# `file`, `xdg-utils` are used by https://github.com/dylanaraps/fff
run dnf install -y file xdg-utils tmux vim git \
 && cd /usr/local/bin && curl https://getmic.ro/r | bash \
 && curl -LO https://github.com/dylanaraps/fff/raw/master/fff && chmod 755 fff \
 && dnf clean all && rm -fr /var/cache/*

# set up environment
run mkdir -p /root/.config/micro \
 && echo 'export EDITOR=micro' >> /root/.bashrc \ 
 && echo -e '{\n "colorscheme": "solarized"\n}' >> /root/.config/micro/settings.json \ 
 && echo -e 'l() {\n  fff "$@"' >> /root/.bashrc \
 && echo '  cd "$(cat "${XDG_CACHE_HOME:=${HOME}/.cache}/fff/.fff_d")"' >> /root/.bashrc \
 && echo '}' >> /root/.bashrc \
 && echo 'export FFF_FAV3=~/mingle'>> /root/.bashrc

# prefer user compiled mingle over the one compiled in physino/geant4:minimal
env PATH=/root/mingle/build:$PATH
