# Monty Project
![monty](images/monty.jpg)

This repo describes an interpreter for Monty bytecode, using Monty byte code file interpreter for stacks and queues data structures (LIFO - FIFO)

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

## Description

This project in the Low Level Programming series is about:

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables
* How to work with git submodules

## Objective - Create a new interpreter to process Monty files

Monty is a scripting language that is first compiled into Monty Byte codes. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files and using doubly linked list as stack or queue while being able to perform operations. The program must be able to process user inputted commands for operations like add or multiple, stack or queue and have no memory leaks.
