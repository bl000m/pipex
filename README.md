# pipex - 42 school project - validated 125/100

=> If you are a 42 student visiting this page for inspiration, please let your inspiration free not to copy/paste the code. Rather look for the logic between the lines and play with it!

# Mandatory part - Rules

The program will be executed as follows:
```
./pipex file1 cmd1 cmd2 file2
```

It must take 4 arguments:

• file1 and file2 are file names.

• cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:

```
$> < file1 cmd1 | cmd2 > file2
```

# Bonus part - Rules

=> Handle multiple pipes

This:
```
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Should behave like:
```
cmd << LIMITER | cmd1 >> file
```

=> Support « and » when the first parameter is "here_doc".

This:
```
$> ./pipex here_doc LIMITER cmd cmd1 file
```

Should behave like:
```
cmd << LIMITER | cmd1 >> file
```
