# CPPO6

The aim of this module was to get acquinted with the different cast available in C++.

### Exercise00: ScalarConverter
This class contains a static method `convert` that takes a string representation of a C++ literal and outputs its value in different scalar types using `static_cast`: char, int, float, and double. The class is designed to handle various types of literals including char, int, float, double, and pseudo literals like `nan`, `-inff`, `+inff`, `-inf`, and `+inf`.

### Exercise01: Serializer
This exercice implements a `Serializer` class that provides static methods to serialize and deserialize pointers to a data structure using a `reinterpret_cast`. This class cannot be initialized by the user directly.

### Exercice02: Identify real type
This exercise implements functions that provide a way to generate objects of derived classes and identify their types using polymorphic behavior without directly including the `typeinfo` header but instead `dynamic_cast`.
