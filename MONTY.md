# File Description

## Compilation & Output

Compile with:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
FIles | Description
----------- | -----------
[main.c](./main.c) | Entry point of the program
[monty.h](./monty.h) | Main header file
[lists.h](./lists.h) | Header file for the lists functions
[get_func.c](./get_func.c) | Function that picks the right function for the instruction
[handler_funcs1.c](./handler_funcs1.c) | Handler functions for the instructions
[handler_funcs2.c](./handler_funcs2.c) | Handler functions for the instructions
[handler_funcs3.c](./handler_funcs3.c) | Handler functions for the instructions
[list_funcs1.c](./list_funcs1.c) | Doubly linked list functions
[list_funcs2.c](./list_funcs2.c) | Doubly linked list functions
[strtow.c](./strtow.c) | String tokenizing functions
[free.c](./free.c) | Handling memory functions
[char.c](./char.c) | Handler functions for ascii instructions
[bf](./bf) | Advanced tasks: Brainf*ck programs

## Monty ByteCode Files

```
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
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

```

To Run the program:

```
 ./monty bytecode_file
```

Available Operation Codes:

| Opcode | Description |
|---------------- | -----------|
|push   | Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack)|
|pall   | Prints all the values on the stack, starting from the to of the stack.|
|pint   | Prints the value at the top of the stack.|
|pop    | Removes the to element of the stack. |
|swap   | Swaps the top to elements of the stack.|
|add    | Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
|nop    | This opcode does not do anything.|
|sub    | Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|div    | Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mul | Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mod    | Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|#      | When the first non-space of a line is a # the line will be trated as a comment.|
|pchar  | Prints the integer stored in the top of the stack as its ascii value representation.|
|pstr   | Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.|
|rotl   | Rotates the top of the stack to the bottom of the stack.|
|rotr   | Rotates the bottom of the stack to the top of the stack.|
|stack  | This is the default behavior. Sets the format of the data into a stack (LIFO).|
|queue  | Sets the format of the data into a queue (FIFO).|
