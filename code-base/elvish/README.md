# elvish

## Getting Started

### Installation

Install via scoop:

```sh
scoop install elvish
```

### Editor

Currently, the Elvish extension for VSCode has very limited support, lacking basic features like formatting. We'll have to wait for the Elvish ecosystem to mature further.

### Customization

First, install starship:

```sh
scoop install starship
```

Edit the config file `code ~/.elvish/rc.elv` and add the following line:

```elvish
eval (starship init elvish)
```
