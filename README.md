# C - Simple shell


This program functions as a command line interpreter tailored for Unix-like systems. Its purpose is to furnish users with an interface through which they can issue commands and engage with the underlying operating system. Developed in accordance with specified guidelines and the essential criteria mandated by the Holberton School curriculum, this interpreter serves as a tool for effective interaction with the system.

## Usage

### How to compile it
Clone the repository and compile the `.c` files:
```
gcc *.c -o shell
```
then, you can run it as follows:
```
./shell
```

### Input modes
The shell can work both interactively and non-interactively. This means that it accepts input reading from the prompt or through another non-terminal file descriptor.

**Interactive**
```
$ pwd
/home/user
```
**Non-Interactive**
```
echo "pwd" | ./shell
/home/user
```
A command can be passed either using its executable name or its own path. In other words, an executable path is a valid command:
```
$ ls
file.txt img.png my_dir
$ /bin/ls
file.txt img.png my_dir
```
### Built-in commands
Apart from executing any executable file (such as `ls`), it also handles built-in commands, which are coded into the shell. These are:

- **env**

Prints the environment variables, along with its values.
```
$ env
SHELL=/bin/bash
TERM_PROGRAM_VERSION=1.77.3
HOSTNAME=10a9634f2d2e
...
```
- **exit**

Exits the shell from whenever it is running, with the exit code 0.
```
 ./shell
 $ exit 98
  echo $?
  98
  ```

## How it works



The shell operates through a process of tokenization, which involves splitting the input into distinct strings delimited by spaces. This division isolates both the main command and its accompanying arguments. Subsequently, the shell determines whether the used command is an executable program or a built-in command. In the case of an executable program, the shell locates the command by searching within the PATH environment variable. It then proceeds to transmit the necessary arguments to the execve function for execution. Conversely, if the command is a built-in one, the shell identifies the specific built-in command by searching within an index. Once identified, the shell executes the corresponding function associated with that built-in command.


## Authors

Gabriel Rossy <6747@holbertonstudents.com>

Miguel Damasco <6318@holbertonstudents.com>
