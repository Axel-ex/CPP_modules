# Exercise02: PmergeMe

## About
PmergeMe is a program designed to sort a sequence of positive integers using the merge-insert sort algorithm. It takes a positive integer sequence as an argument and outputs the sorted sequence along with the time taken by the algorithm using two different containers: `std::vector` and `std::deque`.

## Usage
To use this program, follow these steps:
1. Compile the program using the provided Makefile (`make`).
2. Run the program with the command `./PmergeMe <integer_sequence>` where `<integer_sequence>` is the sequence of positive integers you want to sort.

## Implementation
The program is implemented in C++ and utilizes the merge-insert sort algorithm to sort the positive integer sequence. It consists of the following components:

- **Input Parsing**: Reads the command-line arguments and converts them into a sequence of positive integers.
- **Merge-Insert Sort**: Implements the merge-insert sort algorithm using both `std::vector` and `std::deque` containers.
- **Execution Time Measurement**: Measures the execution time of the sorting algorithm using both containers.
- **Output Formatting**: Displays the unsorted and sorted sequences along with the time taken by each container.
