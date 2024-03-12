# CPP09

This project aimed to explore the Standard Template Library (STL) and get acquinted with the containers and algorithms it offers. More info about subject requirements here: [subject](en.subject.pdf).

### Exercise00: Bitcoin Exchange
This program, named `btc`, calculates the value of a certain amount of bitcoin on a given date using a provided CSV database containing bitcoin prices over time. maps were used in this exercice to keep in memory associations of date and exchange rate to later be able to calculate bitcoin value at specific time points.

### Exercise01: Reverse Polish Notation
This program, named `RPN`, computes the result of a mathematical expression provided in Reverse Polish Notation (RPN). It supports basic arithmetic operations such as addition (+), subtraction (-), multiplication (*), and division (/). lists were used to parse the input into a token list and a stack was used to simulate the execution of the expression.

### Exercise03: PmergeMe
This program, named `PmergeMe`, sorts a sequence of positive integers using the merge-insert sort algorithm (Ford-Johnson algorithm). It uses two different container (`std::vector` and `std::deque`) and measures the time taken by the algorithm to sort them.
