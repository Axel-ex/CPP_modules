# Exercise02: No, you need form 28B, not 28C..

In this project, we implement the AForm abstract base class and three concrete form classes: ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm. Each concrete form class represents a different bureaucratic task, including creating shrubbery, performing robotomy, and granting presidential pardons.

## AForm (Abstract Base Class)

### Constructors and Destructor
- **AForm**: Constructs a form with a name and required sign and execute grades. Throws exceptions if grades are out of bounds.
- **Copy constructor**: Copies a form object.
- **Destructor**: Destroys a form object.

### Operator Overload
- **Assignment operator**: Assigns the sign status of one form object to another.
- **Insertion operator (<<)**: Overloaded to print all the form's information.

### Getters and Setters
- **getName()**: Gets the name of the form.
- **IsSigned()**: Checks if the form is signed.
- **getSignGrade()**: Gets the grade required to sign the form.
- **getExecGrade()**: Gets the grade required to execute the form.

### Member Function
- **beSigned()**: Changes the sign status of the form if the bureaucrat's grade is high enough.
- **GradeTooHighException**: Exception thrown when the grade is too high.
- **GradeTooLowException**: Exception thrown when the grade is too low.

## Concrete Form Classes

### ShrubberyCreationForm

#### Constructors and Destructor
- **ShrubberyCreationForm**: Constructs a form for creating shrubbery.
- **Copy constructor**: Copies a ShrubberyCreationForm object.
- **Destructor**: Destroys a ShrubberyCreationForm object.

#### Operator Overload
- **Assignment operator**: Assigns the sign status of one ShrubberyCreationForm object to another.
- **Insertion operator (<<)**: Overloaded to print all the form's information.

#### Member Function
- **execute()**: Creates a file with ASCII art of shrubbery in the working directory.

### RobotomyRequestForm

#### Constructors and Destructor
- **RobotomyRequestForm**: Constructs a form for performing robotomy.
- **Copy constructor**: Copies a RobotomyRequestForm object.
- **Destructor**: Destroys a RobotomyRequestForm object.

#### Operator Overload
- **Assignment operator**: Assigns the sign status of one RobotomyRequestForm object to another.
- **Insertion operator (<<)**: Overloaded to print all the form's information.

#### Member Function
- **execute()**: Makes drilling noises and informs if the robotomy was successful.

### PresidentialPardonForm

#### Constructors and Destructor
- **PresidentialPardonForm**: Constructs a form for granting presidential pardons.
- **Copy constructor**: Copies a PresidentialPardonForm object.
- **Destructor**: Destroys a PresidentialPardonForm object.

#### Operator Overload
- **Assignment operator**: Assigns the sign status of one PresidentialPardonForm object to another.
- **Insertion operator (<<)**: Overloaded to print all the form's information.

#### Member Function
- **execute()**: Informs that the target has been pardoned by Zaphod Beeblebrox.

