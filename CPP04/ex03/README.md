# Exercice03: 

This exercice aims to get acquinted with the concept of pure abstract class or Interface by implementing a pure abstract class AMateria representing a type of materia one can potentially use in a game. Since Materias can't be deleted by the player, a singleton class was implemented to keep track of allocated memory to be able to properly free it upon exit.
## Components

1. **AMateria Class**: 
   - The `AMateria` class serves as the base abstract class for all magical materials in the game.
   - Features include:
     - A `type` attribute to store the type of material.
     - Pure virtual functions `clone()` and `use()` for material behavior.

2. **Ice and Cure Classes**:
   - Concrete classes `Ice` and `Cure` extend from `AMateria`.
   - Implementations include `clone()` and `use()` specific to each material type.

3. **ICharacter Interface**:
   - Interface defining character behavior in the game.
   - Pure virtual functions include `getName()`, `equip()`, `unequip()`, and `use()`.

4. **Character Class**:
   - Concrete class implementing the `ICharacter` interface.
   - Manages a character's inventory of materials and associated actions.

5. **IMateriaSource Interface**:
   - Interface representing a source of materials.
   - Functions include `learnMateria()` and `createMateria()`.

6. **MateriaSource Class**:
   - Concrete class implementing `IMateriaSource`.
   - Handles the learning and creation of materials.

### Memory Management Approach
   - Materials unequipped by characters are not immediately deleted but are stored for later cleanup.
   - Utilize a singleton class called `Floor` to manage dropped materials that are not currently equipped.
   - This approach prevents immediate deletion of unequipped materials and allows for centralized cleanup.
   - **DISCLAIMER** STL is not allowed in this module hence the need to implement a list structure.
