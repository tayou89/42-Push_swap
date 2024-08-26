# Push_swap

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. The goal is to create an efficient sorting algorithm using two stacks.

## Compilation

The project includes a Makefile with the following rules:

- `make`: Compiles the mandatory part
- `make bonus`: Compiles the bonus part
- `make clean`: Removes object files
- `make fclean`: Removes object files and executables
- `make re`: Recompiles the project

## Norminette

This project follows the Norm, the programming standard of 42 School. The Norm includes rules for naming conventions, function limitations, forbidden keywords and features, file organization, and header file protection. For detailed information, refer to the `nominette.pdf` in the `requirements` folder.

## Mandatory Part

The mandatory part implements the `push_swap` program, which calculates and displays the smallest program of Push_swap instructions that sorts the integer arguments received.

## Bonus Part

The bonus part implements the `checker` program, which takes integer arguments and reads instructions on the standard input. The checker executes these instructions and determines whether the stack is sorted after their execution.

## Usage

### push_swap

```
./push_swap [list of integers]
```

Example:
```
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

This example sorts the list [2, 1, 3, 6, 5, 8] and outputs the operations needed to sort it.

### checker (bonus)

```
./push_swap [list of integers] | ./checker [list of integers]
```

Example:
```
$ ./push_swap 3 2 1 | ./checker 3 2 1
OK
```

This example sorts the list [3, 2, 1] using push_swap, then passes the operations to checker, which verifies if the list is correctly sorted.

You can also use checker interactively:
```
$ ./checker 3 2 1
rra
pb
sa
rra
pa
OK
```

In this case, you input the operations manually, and checker verifies if they correctly sort the list.

## Algorithm

The sorting algorithm implemented in this project efficiently sorts the given integers using two stacks and a limited set of operations. It aims to minimize the number of actions required to sort the stack.

## Note

This project is part of the 42 School curriculum and adheres to specific requirements and constraints outlined in the `push_swap.pdf` file located in the `requirements` folder.