#!/usr/bin/env bash
sudo apt update
sudo apt install watchman
# bundler is required in ruby 2
gem install bundler
bundle install
# bundle exec tapioca init
