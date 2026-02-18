# nushell

A data-driven, cross-platform modern shell.

## Getting Started

### Installation

Windows installation:

```sh
winget install nushell
```

### Environment

Currently I use VSCode as my development environment, but VSCode's Nushell extension ecosystem is not very mature yet. It only has basic features like syntax highlighting and completion. Debugging, code formatting, and other features haven't caught up. We can only hope that the Nushell ecosystem will continue to improve in the future.

Running code uses the most straightforward approach - switch to the corresponding directory in the terminal and manually run the shell file to execute it.

- [nushell vscode extension](https://github.com/nushell/vscode-nushell-lang)

TODO: Currently all code is unformatted. We'll have to wait for the extension to add these features in the future.

### Help

View help for a command.

```nushell
help str
```

## Configuration

### Default Configuration Files

The default configuration files are specified by `$nu.config-path` and `$nu.env-path`.

```sh
code $nu.config-path
```

Modify the default editor `buffer_editor`

```nushell
let-env config = {
  ...

  buffer_editor: "code"
  ...
}
```

After this, you can use `config env` or `config nu` to edit the configuration files.

### Beautification

#### starship

Run `config env` and add the following two lines.

```nushell
mkdir ~/.cache/starship
starship init nu | save ~/.cache/starship/init.nu
```

Run `config nu` and add the following line at the end.

```nushell
source ~/.cache/starship/init.nu
```

#### oh-my-posh

Install via scoop, which will install both the oh-my-posh program and the theme configuration file (path specified by the environment variable `POSH_THEMES_PATH`).

```sh
scoop install https://github.com/JanDeDobbeleer/oh-my-posh/releases/latest/download/oh-my-posh.json
```

Font installation (requires administrator privileges), or you can manually install nerdfonts.

```sh
oh-my-posh font install
```

Generate the default configuration

```sh
oh-my-posh init nu
```

Run `config nu` and add the following line at the end.

```sh
source ~/.oh-my-posh.nu
```

Themes can be viewed in the [oh-my-posh themes documentation](https://ohmyposh.dev/docs/themes). To change themes, simply regenerate the configuration file.

```nushell
oh-my-posh init nu --config $"($env.POSH_THEMES_PATH)/M365Princess.omp.json"
```

### Autojump

Installation

```cmd
scoop install zoxide
```

Generate the configuration file

```nushell
zoxide init nushell | save ~/.zoxide.nu
```

Run `config nu` and add a line at the end.

```nushell
source ~/.zoxide.nu
```
