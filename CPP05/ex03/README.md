# Exercise03: At least this beats coffee-making

In this project, we implement the Intern class, which is responsible for creating form objects based on user requests. The Intern class has a `makeForm()` function that takes the name of a form and a target as parameters and returns a pointer to a Form object.

## Intern Class

### Constructors and Destructor
- **Intern()**: Constructs an Intern object.
- **Copy constructor**: Copies an Intern object.
- **Destructor**: Destroys an Intern object.

### Operator Overload
- **Assignment operator**: Assigns one Intern object to another.

### Member Functions
- **makeForm()**: Creates a Form object based on the form name and target passed as parametersusing an array of member function pointers. If the form name doesn't exist, it throws a FormRequestException.
- **makeShrubberyForm()**: Creates a ShrubberyCreationForm object with the specified target.
- **makeRobotomyForm()**: Creates a RobotomyRequestForm object with the specified target.
- **makePresidentialForm()**: Creates a PresidentialPardonForm object with the specified target.

## FormRequestException Class

### Member Function
- **what()**: Overrides the what() function to provide a custom error message for form request exceptions.


