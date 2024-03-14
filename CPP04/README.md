# CPP04

This module delves into the world of subtype polymorphism, abstract classes, and interfaces. See [subject](en.subject.pdf).

### Exercise 00: Polymorphism
Exercise 00 introduces you to the concept of polymorphism. You'll create base and derived classes such as `Animal`, `Dog`, and `Cat`, where each derived class overrides member functions to exhibit specific behaviors. This exercise lays the foundation for understanding inheritance and dynamic polymorphism.

### Exercise 01: I don't want to set the world on fire
Building on polymorphism, Exercise 01 focuses on memory management. You'll implement a `Brain` class and manage dynamic memory allocation and deallocation in derived classes like `Dog` and `Cat`. Deep copying and memory management are the key highlights of this exercise.

### Exercise 02: Abstract Class
This exercice delves into abstract classes. The default `Animal` class is made abstract by setting the virtual method `makeSound() = 0`. It prevent direct instantiation, emphasizing the concept of abstraction. You'll learn how to design abstract classes and ensure that only derived classes like `Dog` and `Cat` can be instantiated.

### Exercise 03: Interfaces & recap
In Exercise 03, you'll dive into interfaces using pure abstract classes. Implementing interfaces for various classes like `AMateria`, `ICharacter`, and `IMateriaSource`, you'll explore polymorphic behavior and dynamic dispatch. This exercise emphasizes interface design and its role in achieving polymorphism.
