import subprocess

import rich

prog = subprocess.run("ls".split(" "), shell=True, check=True, capture_output=True)

rich.print(prog)
