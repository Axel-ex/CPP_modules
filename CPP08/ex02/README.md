# Exercice02: MutantStack

The MutantStack class is designed to enhance the functionality of the std::stack container by making it iterable. It provides iterators in addition to all the member functions of std::stack.

## Implementation Details

The MutantStack class includes the following functionalities:

- **Constructor**: Constructs a MutantStack object.
- **Iterators**: Provides iterators for traversing the elements of the MutantStack.
  - `begin()`: Returns an iterator pointing to the first element.
  - `end()`: Returns an iterator referring to the past-the-end element.
  - `cbegin()`: Returns a const iterator pointing to the first element.
  - `cend()`: Returns a const iterator referring to the past-the-end element.

