# 0x19. C - Stacks, Queues - LIFO, FIFO

Stacks and Queues Using C language

## About

### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line.

There can be any number of spaces before or after the opcode and its argument:

``` main.bash
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

Monty byte code files can contain blank lines empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

``` main.bash
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

## Installation

Clone the repo to your system using:

`git clone https://www.github.com/mide2020-16/monty.git`

but you must have git installed.

Then run the compile and run the program and use.

### Usage

`monty <file>`

## Compilation

### Linux (Ubuntu 20.04)

`$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

## Contributions

You can aswell contribute to the completion of this project by just "forking" it to your repo and make significant changes in the code but in a different branch.

Then make a pull request to us.

Also you can raise up an issue in the issue section and we would do well to attend to it as soon as possible.

## Authors

Efuwape Ayomide Oreoluwa (westfire)

Atueyi Jennifer (jey)

With love from `#ALX - doing hard things`
