# Exercise02: Array

This exercice aim to develop a class template `Array` that contains elements of type `T` and implements various behaviors and functions.

### Class Template `Array`
The `Array` class template provides the following functionality:
- Construction with no parameter: Creates an empty array.
- Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
- Copy construction and assignment operator: Modifying either the original array or its copy after copying must not affect the other array.
- Accessing elements through the subscript operator: `[]`.
- Throw `std::out_of_range` exception when accessing an element with the `[]` operator if its index is out of bounds.
- A member function `size()` that returns the number of elements in the array. This member function does not modify the current instance.

