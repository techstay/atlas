#!/usr/bin/env bash
set -euo pipefail

sudo sh -c "$(curl -fsSL https://starship.rs/install.sh)" "" --yes

echo 'eval "$(starship init bash)"' >> /home/vscode/.bashrc
echo 'eval "$(starship init zsh)"' >> /home/vscode/.zshrc
mkdir -p /home/vscode/.config/fish
echo 'eval "$(starship init fish)"' >> /home/vscode/.config/fish/config.fish

curl -fsSL https://xmake.io/shget.text | bash
