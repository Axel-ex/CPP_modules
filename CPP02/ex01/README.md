## Exercise 01: Towards a more useful fixed-point number class

This exercise enhance the Fixed Point Number class created in Exercise 00 to make it more useful. The class will now support the following additional functionality:

### Public Constructors:
- A constructor that takes a constant integer as a parameter and converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8.
- A constructor that takes a constant floating-point number as a parameter and converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8.

### Public Member Functions:
- A member function `float toFloat() const;` that converts the fixed-point value to a floating-point value.
- A member function `int toInt() const;` that converts the fixed-point value to an integer value.

### Other Additions:
- An overload of the insertion (<<) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as a parameter.

### Implementation Overview:
The implementation focuses on extending the functionality of the Fixed Point Number class to handle integer and floating-point inputs, as well as providing methods to convert fixed-point values to floating-point and integer representations.

For the integer constructor, the integer value is directly shifted 8 times to the left, effectively multiplying the number by `2^8` (256), which positions the fixed-point decimal part.

Similarly, for the float constructor, the float value is multiplied by a scale factor of 256, ensuring that the fractional part is preserved in the integer representation. This technique allows for calculations involving floating-point numbers at a low computational cost, making it efficient for various numerical operations.
