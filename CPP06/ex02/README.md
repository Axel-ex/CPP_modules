# Exercise02: Identify real type
This exercise implements functions taht provide a way to generate objects of derived classes and identify their types using polymorphic behavior without directly including the `typeinfo` header.

### Implementation:

- **generate**: This function randomly instantiates an object of type A, B, or C, and returns it as a Base pointer. The random choice is implemented using the `rand()` function.

- **identify (pointer)**: This function identifies the actual type of the object pointed to by the Base pointer `p`. It uses `dynamic_cast` to check if the pointer can be cast to A, B, or C, and prints the corresponding type.

- **identify (reference)**: This function identifies the actual type of the object referenced by the Base reference `p`. It uses `dynamic_cast` in a try-catch block to attempt casting to A, B, or C. If successful, it prints the corresponding type.

These functions provide a way to generate objects of derived classes and identify their types using polymorphic behavior without directly including the `typeinfo` header.

