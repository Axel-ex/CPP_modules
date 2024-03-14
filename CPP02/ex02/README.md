# Exercise02: Now we’re talking

In this exercise, we build upon the Fixed Point Number class introduced in the previous exercises, extending its functionality to include operator overloading and additional member functions for arithmetic operations and comparisons.

## Implementation Overview
The Fixed Point Number class now supports overloading of various operators including comparison operators (> < >= <= == !=) and arithmetic operators (+ - * /). Additionally, both pre-increment, post-increment, pre-decrement, and post-decrement operators have been implemented to manipulate fixed-point values while ensuring that the smallest representable epsilon is maintained.

## Operator Overloading
The class now overloads the following operators:
- Comparison Operators: >, <, >=, <=, ==, !=
- Arithmetic Operators: +, -, *, /
- Increment/Decrement Operators: ++, --

## Static Member Functions
Four static member functions have been added to the class:
- `min`: Returns a reference to the smaller of two fixed-point numbers.
- `max`: Returns a reference to the larger of two fixed-point numbers.

## Conclusion
With these enhancements, the Fixed Point Number class becomes more versatile and suitable for a wider range of applications requiring fixed-point arithmetic and comparisons.

