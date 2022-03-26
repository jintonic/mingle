FROM physino/geant4:11.0.1

RUN dnf update -y \
  && git clone https://github.com/jintonic/mingle.git && cd mingle \
  && mkdir build && cd build && cmake .. && make && mv mingle /usr/bin \
  && dnf clean all && rm -fr /var/cache/*

WORKDIR /root/mingle
CMD ["mingle"]
