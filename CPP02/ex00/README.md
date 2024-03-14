# Exercise00: My First Class in Orthodox Canonical Form

This exercise introduces the concept of fixed-point numbers and guides you through the creation of a class to handle them in C++. Fixed-point numbers offer a balance between performance, accuracy, range, and precision, making them particularly useful in various applications such as computer graphics, sound processing, and scientific programming.

## Exercise 00: Fixed Point Number Class

This exercis implements a class to represent fixed-point numbers in C++. The class is designed following the Orthodox Canonical Form and will include the following components:

### Class Structure:
- **Private Members:**
  - An integer to store the fixed-point number value.
  - A static constant integer to store the number of fractional bits, which will always be 8.

- **Public Members:**
  - A default constructor that initializes the fixed-point number value to 0.
  - A copy constructor.
  - A copy assignment operator overload.
  - A destructor.
  - A member function `int getRawBits() const;` that returns the raw value of the fixed-point number.
  - A member function `void setRawBits(int const raw);` that sets the raw value of the fixed-point number.


