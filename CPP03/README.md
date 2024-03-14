# CPP03

This project dives into C++ classes with a focus on inheritance, aiming to solidify understanding of Object-Oriented Programming (OOP) concepts. See [subject](en.subject.pdf).

### Exercise 00: Aaaaand... OPEN!
- **ClapTrap class:** Base class implemented using the canonical form, featuring private attributes and public member functions for attacking, taking damage, and being repaired.

### Exercise 01: Serena, my love!
- **ScavTrap class:** Derived from `ClapTrap`, adds a new member function `guardGate` and inherites from all members of the base class. Public inheritance makes derived classes able to access public members of their Base class. Introduction of the protected members accessible by the class and its child.

### Exercise 02: Repetitive work
- **FragTrap class:** Derived from ClapTrap, adds `highFivesGuys` member function.

### Exercise 03: Handling the Diamond Problem
- **DiamondTrap class:** Inherits from both `FragTrap` and `ScavTrap`, combining their functionalities. Introduces the `whoAmI` member function to display the name of the `DiamondTrap` instance.
  
This exercise explores the concept of multiple inheritance, which can lead to the "diamond problem" when a derived class inherits from two or more classes that themselves share a common base class. The ambiguity arises when the derived class cannot distinguish which base class a particular feature was inherited from.

To resolve this ambiguity, the `virtual` keyword is used in the base class declaration. This ensures that only one instance of the common base class is shared among the derived classes, preventing redundant inheritance and resolving the diamond problem effectively. In the contexte of multiple inheritance, the scope resolution operator is also used to access members of a specific base.
