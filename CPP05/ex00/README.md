# Exercise00: Mommy, when I grow up, I want to be a bureaucrat!

This project focuses on implementing a Bureaucrat class, which represents an individual with a name and a grade within a bureaucratic system. The grade ranges from 1 (highest) to 150 (lowest). The class provides functionality to manage the grade, including incrementing and decrementing it, while ensuring that it remains within the valid range. Invalid grade values result in exceptions being thrown.

Below is a summary of the Bureaucrat class implementation:

### Implementation:

- **Constructor**: Initializes a Bureaucrat with a given name and grade. If the grade is out of range (above 1 or below 150), it throws either a `Bureaucrat::GradeTooHighException` or a `Bureaucrat::GradeTooLowException`.

- **Copy Constructor**: Copies a Bureaucrat object.

- **Destructor**: Destroys a Bureaucrat object.

- **Assignment Operator**: Assigns the grade of one Bureaucrat object to another.

- **Operator Overload**: Overloads the insertion operator (`<<`) to print the name and grade of a Bureaucrat.

- **Getters**: Provides getter methods `getName()` and `getGrade()` to retrieve the name and grade of a Bureaucrat.

- **Increment Grade**: Increments the grade of the Bureaucrat by one. If the grade is already at the maximum (1), it throws a `Bureaucrat::GradeTooHighException`.

- **Decrement Grade**: Decrements the grade of the Bureaucrat by one. If the grade is already at the minimum (150), it throws a `Bureaucrat::GradeTooLowException`.

- **GradeTooHighException**: Exception thrown when the grade is too high.

- **GradeTooLowException**: Exception thrown when the grade is too low.
