# bash-examples

This project is a collection of small Bash examples for learning shell syntax and common scripting patterns. The examples are grouped by topic, and each `.sh` file focuses on one specific concept.

## Project Structure

```text
bash-examples/
├── 01.basic/            # Basic syntax: variables, conditions, loops, strings, quoting
├── 02.input-output/     # Input and output: read, redirection, here docs, pipelines, arguments
├── 03.data-structures/  # Data structures: indexed arrays and associative arrays
├── 04.functions/        # Functions: definitions, scope, and return values
├── 05.operators/        # Operators: file tests, numeric comparisons, string checks
├── 06.advanced/         # Advanced topics: expansion, debugging, error handling, process substitution, subshells
├── 07.scripting/        # Scripting practices: strict mode, logging, cleanup, main function
└── .vscode/             # Local VS Code settings
```

## Environment Requirements

### Required

- Bash 4 or newer
  - Linux usually includes Bash by default.
  - macOS includes Bash, but the system version may be older.
  - On Windows, Git Bash, WSL, or another Bash-compatible environment is recommended.

### Recommended

- ShellCheck: checks shell scripts for common issues.
- shfmt: formats shell scripts.
- VS Code: useful with the included local editor settings.
- Git Bash: recommended Bash environment on Windows.

## Running Examples

Run an example from the project root:

```sh
bash 01.basic/01.hello_world.sh
```

Run an example with arguments:

```sh
bash 02.input-output/05.command_args.sh first second
```

Some examples intentionally demonstrate errors, debugging behavior, early exits, or file redirection side effects. Read the comments in each script before running examples that change files or intentionally fail.

## Checking Scripts

Check syntax for all scripts:

```sh
find . -name "*.sh" -print0 | xargs -0 -n1 bash -n
```

Run ShellCheck:

```sh
shellcheck $(find . -name "*.sh")
```

Format all shell scripts:

```sh
shfmt -w .
```

## Development Notes

`.vscode/settings.json` runs `shfmt -w ${file}` when saving `.sh` files through the configured Run on Save extension. If `shfmt` is not installed, automatic formatting will not work.

After editing Markdown files, format them with Prettier:

```sh
bunx prettier --write README.md
```
