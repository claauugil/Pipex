
## Pipex

Pipex is a program that simulates the behavior of shell pipes in Unix-like systems. The goal of the project is to handle pipes and processes, using system calls to redirect input and output between commands.

## Description

This project involves managing pipes and processes. Specifically, it takes the output of the first command and uses it as the input for the second command. Here's what it does:

- Parse the input arguments.
- Set up pipes to redirect input/output between cmd1 and cmd2.
- Execute the commands using system calls, ensuring proper redirection of file descriptors.
- Write the output of cmd2 to file2.
## Usage

The program should be executed as follows:


```bash
  ./pipex file1 "cmd1" "cmd2" file2
```

Arguments: 

- File1: Name of the input file.
- Cmd1: The first shell command with its arguments.
- Cmd2: The second shell command with its arguments.
- File2: Name of the output file.

The program will achieve the same result as the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```


## Example

* Execute

```bash
./pipex infile "ls -l" "wc -l" outfile
```

Equivalent to: 

```bash
< infile ls -l | wc -l > outfile
```
## Function Descriptions:

Here is a summary of the most important functions used in the pipex project:


_Handle_first_child / handle_sec_child:_
- Manages the behavior of the child processes.
- Prepares the pipe for the first and second command using prep_pipe.
- Closes unused file descriptors using close_fds.
- Executes the commands with exec.
- Handles execution errors if exec fails.

_prep_pipe_ : Redirects file descriptors for the current process:

- Uses dup2 to link the input file descriptor to STDIN_FILENO.
- Links the output file descriptor to STDOUT_FILENO.

_exec_ : Executes a command

- Parses the command and its arguments using ft_split.
- Finds the executable path using get_exec.
- Runs the command with execve. If it fails, execution returns to print an error.

_get_path_ : Retrieves the system PATH environment variable:

- Iterates through the environment variables to find PATH.
- Splits the paths into an array using ft_split.
- Terminates the program with an error message if PATH is not found.

_get_exec_ : Constructs the full executable path for a command:

- Appends the command name to each directory in the PATH using ft_strjoin.
- Checks if the constructed path is executable with access.
- Returns the valid path or NULL if not found.
