# Exercise01: Serializer

The `Serializer` class provides static methods to serialize and deserialize pointers to a data structure. This class cannot be initialized by the user directly.

### Implementation:
- **serialize**: Takes a pointer to a data structure and converts it to the unsigned integer type `uintptr_t`. This method uses `reinterpret_cast` to convert the pointer to an unsigned integer (`uintptr_t`) and returns it. The `reinterpret_cast` conserves the bit pattern of the variable pointed by `uintptr_t`

- **deserialize**: Takes an unsigned integer parameter and converts it back to a pointer to the original data structure. Because the bit pattern was conserved, the data is not modified.

