# Exercice00: Bitcoin Exchange

## About
This program, named `btc`, is designed to calculate the value of a certain amount of bitcoin on a given date. It utilizes a database in CSV format containing bitcoin prices over time. The program takes as input a file specifying different dates and values to evaluate.

## Usage
To use this program, follow these steps:
1. Ensure you have the required CSV database file (data/data.csv).
2. Compile the program using the provided Makefile (`make`).
3. Run the program with the command `./btc <input_file>` where `<input_file>` is the file containing dates and values to evaluate.

### Example
Each line in the input file should follow the format: `date | value`. Dates must be in the format `Year-Month-Day`, and values can be either a float or a positive integer between 0 and 1000.

```
2024-03-01 | 10.5

2024-03-02 | 15
````

## Implementation
The program is implemented in C++ and utilizes the Standard Template Library (STL). The `BitcoinExchange` class handles loading the database and computing the bitcoin value for each input date. Here's an overview of the key methods:

- `loadDataBase()`: Loads bitcoin price data from the provided CSV database file.
- `compute()`: Processes each line from the input file to calculate the bitcoin value on the specified date.
- `processLine()`: Extracts date and value from each line and computes the bitcoin value.
- `matchDate()`: Finds the closest date in the database to the input date.
- `strToTime()`: Converts a string date to a time_t object.
- `timeToStr()`: Converts a time_t object to a string date.
- `isDateFormat()`: Checks if a date string is properly formatted.
