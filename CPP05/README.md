# CPP05

CPP05 introduces the world of bureaucratic paperwork simulation in C++. The exercises focus on implementing classes to represent bureaucrats, forms, and interns, each with specific functionalities and interactions. See [subject](en.subject.pdf).


### Exercise00: Mommy, when I grow up, I want to be a bureaucrat!
This exercise implements a Bureaucrat class. The Bureaucrat class represents individuals with a name and a grade, and it provides methods for incrementing and decrementing the grade. The class also implement its own exceptions in the case the grade is too low or high.

### Exercise01: Form up, maggots!
this exercise implements the Form class to simulate bureaucratic paperwork. The Form class encapsulates details about a form, including its name, sign status, and the grades required to sign and execute it. The grades follow the same rules as the Bureaucrat class, with exceptions thrown if they are out of bounds.

### Exercise02: No, you need form 28B, not 28C..
In this exercise, concrete form classes are implemented by deriving from an abstract base class `AForm`: `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`. Each form has specific sign and execution grades and performs different actions when executed. The `execute()` function is added to the base Form class to execute the form's action based on the concrete class.

### Exercise03: At least this beats coffee-making
The Intern class is introduced to support the automated creation of different forms based on user requests. It implements separate functions for creating each type of form object: `makeShrubberyForm()`, `makeRobotomyForm()`, and `makePresidentialForm()`. The correct function is called depending on the name of the form the intern receives using an array of member function pointers. If an invalid form type is requested, it throws a `FormRequestException`.


