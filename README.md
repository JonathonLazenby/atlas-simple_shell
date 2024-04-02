# Simple Shell

**Description:**
A shell in an extremely basic form, meant to do similar stuff as Unix. Command line interpreter/interface between user
and kernel. executing programs called commands to navigate the system. Supposed to prompt you to enter a command, pa-
rse through what was entered, look for either a system call in the environment or built-in command included in your compiled files, finish executing whichever is chosen within the child process, then finish the parent process and loop back to the prompt.
for example: user enters ls and executes to see a list of current files/directories in the current working directory.

**Purpose:**
To showcase what we have learned in these last few months, while also showing where we can improve. 

# Included Files
- Shell.c - super simple shell
- README.md - Introduction, description, and general information.
- shell3 - Another earlier version of super simple shell to help with some problmes in Shell.c that we were stuck on.
# Installation
- Clone current Repo
- cd to atlas-simple_shell
- gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
- run ./ hsh

# Bugs
*INCOMPLETE*
Has quite a few bugs and is not complete.
# License
Open Source for Atlas school project no license needed.

# Authors 

- Kiko Sprague <ksprague0592@gmail.com>
- Jonathon Lazenby <>

# Project Status
Currently at a halt would like to work on it more in the future to get it to do what it should be doing now.
