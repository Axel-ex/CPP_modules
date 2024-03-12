# Exercice03: 

Welcome to the world of Magical Materias! In this project, you'll be implementing a game framework where characters can interact with various magical materials to cast spells and perform enchantments. Let's dive into the components of this project:

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

## Additional Considerations

- **Memory Management**: Ensure proper memory allocation and deallocation to avoid memory leaks.
- **Testing**: Thoroughly test the functionality of each class and interface to ensure correctness.
- **Deep Copy**: Pay special attention to deep copying of the `Character` class as it involves managing inventory.

## Memory Management Approach

1. **Dynamic Memory Allocation**: 
   - Use dynamic memory allocation for materials to ensure proper lifetime management.

2. **Unequip Functionality**:
   - Materials unequipped by characters are not immediately deleted but are stored for later cleanup.

3. **Floor Singleton Class**:
   - Utilize a singleton class called `Floor` to manage dropped materials that are not currently equipped.
   - This approach prevents immediate deletion of unequipped materials and allows for centralized cleanup.

4. **Singleton Pattern**: 
   - Implement `Floor` as a singleton to ensure global access and centralized management of dropped materials.

## How the Floor Singleton Works

- **Dropping Materias**: Unequipped materials are dropped onto the `Floor` using the `dropMateria()` function.
- **Later Deletion**: Materials dropped on the `Floor` are kept track of until they are explicitly deleted during cleanup.
