FROM fedora
RUN dnf update -y \
  && dnf install -y boost-devel clang clang-tools-extra cmake exa which \
  && sh -c "$(curl -fsSL https://starship.rs/install.sh)" "" --yes \
  && echo 'eval "$(starship init bash)"' >> /root/.bashrc
