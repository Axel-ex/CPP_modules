# Exercise00: ScalarConverter

This class contains a static method `convert` that takes a string representation of a C++ literal and outputs its value in different scalar types: char, int, float, and double. The class is designed to handle various types of literals including char, int, float, double, and pseudo literals like `nan`, `-inff`, `+inff`, `-inf`, and `+inf`.

### Implementation
The class contains several static helper methods to determine the type of the input string:
- `isChar`: Checks if the string represents a character literal.
- `isInt`: Checks if the string represents an integer literal.
- `isFloat`: Checks if the string represents a float literal.
- `isDouble`: Checks if the string represents a double literal.
- `isPseudo`: Checks if the string represents a pseudo literal like `nan`, `-inff`, `+inff`, `-inf`, or `+inf`.

Based on the determined type, the `convert` method calls appropriate conversion functions:
- For char, it converts the character to its ASCII value.
- For int, it converts the string to an integer using `std::stoi`.
- For float, it converts the string to a float using `std::strtof`.
- For double, it converts the string to a double using `std::strtod`.

If the input string does not match any known type, it prints an informative message indicating that the type is not supported.


