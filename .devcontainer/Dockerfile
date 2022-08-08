# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.195.0/containers/cpp/.devcontainer/base.Dockerfile
# [Choice] Debian / Ubuntu version (use Debian 11/9, Ubuntu 18.04/21.04 on local arm64/Apple Silicon): debian-11, debian-10, debian-9, ubuntu-21.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT=debian-11

# Avaiable langs is cpp, go, anaconda, python
ARG LANGUAGE=cpp


FROM mcr.microsoft.com/vscode/devcontainers/${LANGUAGE}:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install build-essential cmake ninja-build pkg-config gdb cppcheck valgrind clang lldb llvm \
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*

RUN mkdir /usr/local/vcpkg && git clone https://github.com/microsoft/vcpkg.git /usr/local/vcpkg &&/usr/local/vcpkg/bootstrap-vcpkg.sh
RUN /usr/local/vcpkg/vcpkg integrate install
