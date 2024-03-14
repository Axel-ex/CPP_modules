# CPP01
This module aims to get acquinted with Memory allocation, pointers to members, references and switch statement. see [subject](en.subject.pdf).

### Exercise00: BraiiiiiiinnnzzzZ

Exercise 00 involves implementing a `Zombie` class with a private attribute `name`. The class includes a member function `announce()` that prints the zombie's name followed by "BraiiiiiiinnnzzzZ...". Additionally, two functions are implemented:
- `Zombie* newZombie(std::string name)`: Creates a new zombie with the given name and returns a pointer to it.
- `void randomChump(std::string name)`: Creates a zombie with the given name and announces it.

The exercise prompts consideration of whether it's better to allocate zombies on the stack or heap, emphasizing the need to properly manage memory, including destruction of zombies when they are no longer needed. The destructor of the `Zombie` class prints a message with the name of the zombie for debugging purposes.

### Exercise01: Moar brainz!

Exercise 01 introduces a function `zombieHorde(int N, std::string name)` that allocates N `Zombie` objects in a single allocation. Each zombie is initialized with the provided name, and the function returns a pointer to the first zombie. The exercise emphasizes proper memory management, including deletion of all zombies to prevent memory leaks.

### Exercise02: HI THIS IS BRAIN

Exercise 02 requires writing a program that initializes a string variable with "HI THIS IS BRAIN" and declares a pointer and a reference to the string. The program prints:
- The memory addresses of the string variable, pointer, and reference.
- The values of the string variable, pointer, and reference. 

The goal is to demystify references by highlighting their similarities to pointers and address manipulation.

### Exercise03: Unnecessary violence

Exercise 03 involves implementing a `Weapon` class with a private attribute `type`, which is a string. The class includes member functions `getType()` and `setType()` to get and set the type of the weapon, respectively. Additionally, two classes `HumanA` and `HumanB` are created, both having a `Weapon` and a name. They include a member function `attack()` that displays the name of the human attacking with their weapon type. The difference between `HumanA` and `HumanB` lies in how they handle the weapon:
- `HumanA` takes the weapon in its constructor and is always armed.
- `HumanB` may not always have a weapon.

This exercice emphasizes the use of references which can't be NULL by definition and always refer the adress of a variable.


### Exercise04: sed is for losers

Exercise 04 involves creating a program that takes a filename and two strings as parameters. It opens the specified file and copies its content into a new file with the extension ".replace", replacing every occurrence of the first string with the second string. File manipulation using C functions is forbidden, and the program must handle unexpected inputs and errors. Tests should be created to ensure the program works as expected.

### Exercise05: Harl 2.0

Exercise 05 tasks the implementation of a `Harl` class with member functions representing different complaint levels: `debug()`, `info()`, `warning()`, and `error()`. Additionally, a public member function `complain(std::string level)` is provided to call the appropriate complaint function based on the level passed as a parameter. The exercise emphasizes the use of pointers to member functions to automate complaints without using a forest of if/else if/else statements.

### Exercise06: Harl filter

Exercise 06 requires creating a program named `harlFilter` that takes a log level as a parameter. It displays all messages from the specified level and above. The exercice aimed to introduce the `switch` statement.
