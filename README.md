# 42_cpp05

## exceptions
In C++, exceptions are a way to handle errors or other exceptional conditions that occur during the execution of a program. When an error occurs, an exception can be "thrown" to signal that something went wrong. This exception can then be "caught" by a `catch` block, allowing the program to handle the error gracefully.  

Here is a step-by-step explanation with an example:
1. Define a Custom Exception Class: Create a custom exception class that inherits from `std::exception` and overrides the `what()`method to provide a specific error message.
2. Throw the Exception: In our code, when an error condition is detected, we throw an instance of the custom exception.
3. Use a `try` block to wrap the code that might throw an exception, and a `catch` block to handle the exception.

### Example
Let's create a custom exception for a grade-related error in a `Bureaucrat` class.

#### Define the Custom Exception Class

```cpp
#include <exception>

class GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too low";
    }
};

class GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too high";
    }
};
```

#### Throw the Exception

In the `Bureaucrat` class constructor, we throw the custom exceptions when the grade is out of range.

```cpp
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}
```

#### Catch the Exception

In the `main` function, we use a `try` block to catch and handle the exceptions.

```cpp
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Bureaucrats ===" << std::endl;
    try {
        Bureaucrat A("bob", 151);
    } catch (const GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
```

C++98 introduced exception handling.  

Also the system can throw an exception and terminate.  
In C++, memory allocation using new can throw an exception if it fails to allocate the requested memory. Specifically, it throws a std::bad_alloc exception.  If we think it necessary we could allocate memory using new in a try catch block, but in practice we do not do it.  I think we are ok to terminate the program if something really important as a memory allocation fails.  Unless we are programming for a space station I guess.
