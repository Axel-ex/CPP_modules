# CPP03 ClapTrap Inheritance Project

## Overview
This project dives into C++ classes with a focus on inheritance, aiming to solidify understanding of Object-Oriented Programming (OOP) concepts using C++98 standards.

### Exercise 00: Aaaaand... OPEN!
- **ClapTrap class:** Base class with private attributes and public member functions for attacking, taking damage, and being repaired.

### Exercise 01: Serena, my love!
- **ScavTrap class:** Derived from ClapTrap, adds a new member function `guardGate`.

### Exercise 02: Repetitive work
- **FragTrap class:** Derived from ClapTrap, adds `highFivesGuys` member function.

### Exercise 03: Now it’s weird!
- **DiamondTrap class:** Constructed from both FragTrap and ScavTrap, adds `whoAmI` member function for displaying names.

## Code Explanation
Detailed explanation of each class and main functions:

### `ClapTrap` Class (Exercise 00)
- Constructors and destructor
- Operators: Assignment operator
- Get functions and member functions

### `ScavTrap` Class (Exercise 01)
- Inherits from ClapTrap
- Additional member function: `guardGate`
- Overrides necessary functions

### `FragTrap` Class (Exercise 02)
- Inherits from ClapTrap
- Additional member function: `highFivesGuys`
- Overrides necessary functions

### `DiamondTrap` Class (Exercise 03)
- Inherits from both FragTrap and ScavTrap
- Additional member function: `whoAmI`
- Specialized construction involving a ClapTrap subobject
