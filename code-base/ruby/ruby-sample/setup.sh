#!/usr/bin/env bash

cwd=pwd

# Installing dependencies
sudo pacman -Syu --noconfirm
sudo pacman -S --noconfirm --needed ruby ruby-bundler unzip tldr eza starship
echo 'eval "$(starship init bash)"' >>~/.bashrc

# Installing watchman
cd /opt
curl -L -O https://github.com/facebook/watchman/releases/download/v2025.05.19.00/watchman-v2025.05.19.00-linux.zip
unzip watchman*.zip
rm watchman*.zip
sudo mkdir -p /usr/local/{bin,lib} /usr/local/var/run/watchman
cd watchman*
sudo cp bin/* /usr/local/bin
sudo cp lib/* /usr/local/lib
sudo chmod 755 /usr/local/bin/watchman
sudo chmod 2777 /usr/local/var/run/watchman
cd /opt
rm -rf watchman*

cd $cwd

# Installing gems
bundle install
# tapioca init
