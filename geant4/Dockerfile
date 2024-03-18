from physino/geant4:cli

# install minimal datasets (https://geant4-forum.web.cern.ch/t/11527/2)
run mkdir -p /usr/share/Geant4/data && cd /usr/share/Geant4/data \
 && curl -LO https://cern.ch/geant4-data/datasets/G4ENSDFSTATE.2.3.tar.gz \
 && curl -LO https://cern.ch/geant4-data/datasets/G4PhotonEvaporation.5.7.tar.gz \
 && curl -LO https://cern.ch/geant4-data/datasets/G4EMLOW.8.5.tar.gz \
 && curl -LO https://cern.ch/geant4-data/datasets/G4PARTICLEXS.4.0.tar.gz \
 && tar xf *EN* && tar xf *EM* && tar xf *Ph* && tar xf *PA* && rm -f *.gz 

# install openssh server
run dnf install -y openssh-server && dnf clean all && rm -fr /var/cache/*

# configure ssh server
# https://www.garron.me/en/linux/sshd-no-hostkeys-available-exiting.html
run cd /etc/ssh && ssh-keygen -A && echo 'root:geant4' | chpasswd \
 && sed -i -e 's/^#X11Forwarding no$/X11Forwarding yes/' sshd_config

# ENV settings in a Dockerfile work for the terminal in Docker Desktop,
# but they don't work for a shell created by ssh.
# We need to save those settings directly in ~/.bashrc
run cd /root && echo 'export G4RUN_MANAGER_TYPE=Serial' >> .bashrc \
 && echo 'export TERM="xterm-256color"' >> .bashrc \
 && echo 'export PS1="\[\e[0;32m\]\u@Geant4:\[\e[0;34m\]\w \[\e[0;31m\]\$\[\e[m\] "' >> .bashrc

# https://stackoverflow.com/a/40801773/1801749
expose 22

cmd ["/usr/sbin/sshd", "-D"]
