# Exercise01: Form up, maggots!

In this project, we implement the Form class to simulate bureaucratic paperwork. The Form class encapsulates details about a form, including its name, sign status, and the grades required to sign and execute it. The grades follow the same rules as the Bureaucrat class, with exceptions thrown if they are out of bounds.

Below is a summary of the Form class implementation:

## Constructors and Destructor
- **Form**: Constructs a Form object with a name, sign grade, and execute grade. It throws exceptions if the grades are out of bounds.
- **Copy constructor**: Copies a Form object.
- **Destructor**: Destroys a Form object.

## Operator Overload
- **Assignment operator**: Assigns the sign status of one Form object to another.
- **Insertion operator (<<)**: Overloaded to print all the form's information.

## Getters and Setters
- **getName()**: Gets the name of the form.
- **IsSigned()**: Checks if the form is signed.
- **getSignGrade()**: Gets the grade required to sign the form.
- **getExecGrade()**: Gets the grade required to execute the form.

## Member Functions
- **beSigned()**: Changes the sign status of the form if the bureaucrat's grade is high enough.
- **GradeTooHighException**: Exception thrown when the grade is too high.
- **GradeTooLowException**: Exception thrown when the grade is too low.

