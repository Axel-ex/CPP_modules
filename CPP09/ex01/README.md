# Exercise01: Reverse Polish Notation

## About
This program, named `RPN`, calculates the result of a mathematical expression provided in Reverse Polish Notation (RPN). It supports basic arithmetic operations such as addition (+), subtraction (-), multiplication (*), and division (/). The program takes the RPN expression as a command-line argument and outputs the result on the standard output.

## Usage
To use this program, follow these steps:
1. Compile the program using the provided Makefile (`make`).
2. Run the program with the command `./RPN <RPN_expression>` where `<RPN_expression>` is the mathematical expression in Reverse Polish Notation that you want to evaluate.

### Example
The RPN expression should consist of space-separated tokens representing numbers and operators. Numbers must be integers less than 10, and operators supported are: `+`, `-`, `*`, and `/`.

```shell
$ ./RPN "3 4 +"
7
$ ./RPN "5 2 * 6 /"
1
```
## Implementation
The program is implemented in C++ and consists of the following components:

- **Lexer**: Parses the input RPN expression and tokenizes it into operands and operators.
- **Executor**: Processes the tokenized expression and computes the result using a stack-based approach. numbers are pushed on the stack and when an operator is encountered, the appropriated operation is performed and its result is pushed back to the stack.
- **Error Handling**: Detects and handles errors such as invalid tokens or insufficient operands.
