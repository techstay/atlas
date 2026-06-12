FROM fedora

RUN useradd -m -s /bin/bash vscode \
    && echo "vscode ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers.d/vscode

RUN dnf update -y \
    && dnf install -y \
       gcc gcc-c++ make pkg-config git \
       gdb ccache \
       boost-devel spdlog-devel libcxx-devel libcxxabi-devel \
       clang clang-tools-extra cmake \
       readline-devel ncurses-devel lua-devel \
       eza which curl ripgrep fd-find bat \
       zsh fish \
    && dnf clean all \
    && rm -rf /var/cache/dnf

USER vscode
