# Simple Shell project for Holberton

This is a simple implementation of a **shell** for a linux system. We tried to emulate the behavior
of the ``sh`` language..

# Synopsis

Simply put, the shell is a program that takes commands from the keyboard and gives them to the operating system to
perform. In the past, it was the only user interface available on a Unix-like system such as Linux.
Nowadays, there are graphical user interfaces (GUIs) in addition to command line interfaces (CLIs) such as the shell.

Both GUI and CLI have the same purpose to **interact with the operating system** but their input methods are
different.

Our shell currently handles the executions of executables found in the environmental variable **PATH**, with
or without their full paths, for example it will handle the **ls** command to list the directories and files of your
current working directory as well as **/usr/bin/ls** (full path).

We also created some builtins such as: **env** and **exit**.
To exit the shell you can use the **exit** builtin or hit ctrl + d on your keyboard.

## Environment
* Language: C
* Operating System: Ubuntu 20.04 LTS
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)
* Compiler: gcc
 > **Note:** The code will be compiled using the options: -Wall -Werror -Wextra -pedantic -std=gnu89

## Description of each file:

| Files          |Desription
|:----------------|:-------------------------------:|
|``main.h`` | Hold prototypes of functions, libraries, and headers used.
|``shell.c`` | Main function to execute our shell implementation.
|``getters_function.c`` | Hold functions to get the path from the environment, get a string (getline) from the user, print environment (**env** builtin), and function to return the full path of a command.
|``memory_functions.c`` | Function to free a pointer, double pointer, and our own calloc function to allocate memory for an array.
|``signal_functions.c`` | Ignore **ctrl + c** signal from the keyboard.
|``string_functions.c`` | Functions to manipulate strings.
|``tokenizer_functions.c`` | Functions to make tokens from strings.
|``utility_functions.c`` | **Ignore**: spaces, break lines, and tabs. - **count** spaces - **count** colons - check if the input is a **letter** - **convert** tab to spaces.
|``execution_function.c`` | Function to execute a command or a full path.
|``AUTHORS`` | Authors file.
|``man_1_simple_shell`` | User manual.

## Builtins

> **exit:** exit the shell --> ``Usage: exit``.

> **env:** prints the environmental variables --> ``Usage: env``.

## Modes

In order for our shell to be used in **both** ``interactive`` or ``non interactive`` mode the first thing to do is
to clone this repository.
Then you have to compile the code in the following way:

```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 .c -o hsh```

### Interactive mode:

Once you are in your terminal you have to run:```./hsh```

Thats it you are now running our **hsh** shell in interactive mode.
You can pass commands such as: **pwd** or the full path **/usr/bin/pwd**.

### Non interactive mode:

Run the following command:
```echo "ls -l" | ./hsh```
This will list all the files and directories in your current workinf directory in a long format.

## Flowchart


## Authors

* [Agustin Flom](https://github.com/agusfl)
* [Juan Manuel Reyes](https://github.com/JuanManuelReyes)
