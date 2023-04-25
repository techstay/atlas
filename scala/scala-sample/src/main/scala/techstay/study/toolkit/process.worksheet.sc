// spawning process
val result = os.proc("date").call()
result.exitCode
result.out.text()
