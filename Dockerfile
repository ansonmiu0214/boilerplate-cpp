FROM silkeh/clang:12

RUN apt-get update \
  && apt-get install -y build-essential cmake gdb python3-pip software-properties-common

# Setup Conan package manager
RUN python3 -m pip install conan

# Setup user
RUN useradd -m -g root -G sudo -s /bin/bash dev \
    && echo "dev:dev" | chpasswd \
    && mkdir -p /workarea/build \
    && chown dev:root -R /workarea

USER dev
WORKDIR /workarea

COPY .conan /workarea/.conan
RUN cd /workarea/build \
    && ls \
    && conan install ../.conan  --profile ../.conan/conanprofile.txt
