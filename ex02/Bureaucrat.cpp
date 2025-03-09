/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:07:03 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 10:25:39 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "iostream"
#include "sstream"
#include "exception"

/**
 * Default constructor
 */
Bureaucrat::Bureaucrat() : name("Prostetnic Vogon Jeltz"), grade(150) {
	std::cout << this->name << " === Bureaucrat def constructor called ===" << std::endl;
}

/**
 * Parameterized constructor
 * @param name
 * @param grade
 * 
 * If the validation fails and an exception is thrown, the object will be destructed immediately, 
 * and the destructor will be called
 */
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	validateGrade(grade);
	std::cout << this->name <<  " === Bureaucrat constructor called ===" << std::endl;
}

/**
 * Destructor
 */
Bureaucrat::~Bureaucrat() {
	std::cout << this->name << " === Bureaucrat destructor called ===" << std::endl;
}

/**
 * Copy constructor
 * @param copy
 * 
 * If the validation fails and an exception is thrown, the object will be destructed immediately, 
 * and the destructor will be called
 */
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade) {
	validateGrade(copy.grade);
	std::cout << this->name << " === Bureaucrat copy constructor called ===" << std::endl;
}

/**
 * Assignment operator
 * @param assign
 * @return a reference to the bureaucrat
 * 
 * Using the assignment operator ex b2 = b1;
 */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign) {
	std::cout << this->name << " === Bureaucrat assignment operator called ===" << std::endl;
	if (this != &assign) {
		validateGrade(assign.grade);
		this->grade = assign.grade;
	}
	return *this;
}

/**
 * Get the name of the bureaucrat
 * @return
 */
std::string Bureaucrat::getName() const {
	return this->name;
}

/**
 * Get the grade of the bureaucrat
 * @return
 */
int Bureaucrat::getGrade() const {
	return this->grade;
}

/**
 * throw an exception if the grade is too low
 */
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat exception: Grade too low";
}

/**
 * throw an exception if the grade is too high
 */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat exception: Grade too high";
}

/**
 * overload the << operator
 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

/**
 * Increment the grade of the bureaucrat
 */
void Bureaucrat::incrementGrade() {
	Bureaucrat::validateGrade(this->grade - 1);
	this->grade--;
}

/**
 * Decrement the grade of the bureaucrat
 */
void Bureaucrat::decrementGrade() {
	validateGrade(this->grade + 1);
	this->grade++;
}

/**
 * Helper function to check for the grade and throw an exception if it is too low 
 * or too high
 */
void Bureaucrat::validateGrade(int grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

void Bureaucrat::signForm(AForm& form) const {
	if (form.getGradeToSign() >= this->grade) {
		std::cout << this->name << " signed " << form.getName() << std::endl;
		form.setIsSignedTrue();
	} else {
		std::cout << this->name << " couldn’t sign " << form.getName() << " because " << "unsufficient privileges!" << std::endl;
	} 
}

void Bureaucrat::executeForm(AForm const & form) const {
	if (form.getGradeToExecute() >= this->grade) {
		std::cout << this->name << " executed " << form.getName() << std::endl;
		form.performAction();
	} else {
		std::cout << this->name << "cannot execute" << form.getName() << std::endl;
	}
}