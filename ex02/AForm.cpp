/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:00:34 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/16 11:29:21 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

/**
 * Default constructor for the abstract class AForm
 * Even though an abstract class like AForm cannot be instantiated directly, 
 * it can still have constructors. 
 * These constructors are used to initialize the base part of derived classes. 
 * When a derived class is instantiated, 
 * the constructor of the abstract base class is called to initialize its members.\
 */
AForm::AForm() : name("default form"), isSigned(false), gradeToSign(150), gradeToExecute(1) {
	std::cout << this->name << " === AForm def constructor called ===" << std::endl;
}

/**
 * Parameterized constructor
 * @param name
 * @param gradeToSign
 * @param gradeToExecute
 * 
 * Will throw if gradeToSign or gradeToExecute is out of bounds
 * I decided to make it prettier by using a validate grade util function
 */
AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << this->name << " === AForm constructor called ===" << std::endl;
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

/**
 * Destructor
 */
AForm::~AForm() {
	std::cout << this->name << " === AForm destructor called ===" << std::endl;
}

/**
 * Copy constructor
 * @param copy
 * 
 * Since gradeToSign and gradeToExecute are const members in the AForm class, they can only be initialized once, 
 * either in the constructor or through member initializer lists. This means that once they are set, they cannot be modified. 
 * Therefore, validating these values in the constructors should be sufficient to ensure they remain within valid bounds
 */
AForm::AForm(const AForm& copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
	std::cout << this->name << " === AForm copy constructor called ===" << std::endl;
}

/**
 * Assignment operator
 * 
 * Since gradeToSign and gradeToExecute are const members in the AForm class, they can only be initialized once, 
 * either in the constructor or through member initializer lists. This means that once they are set, they cannot be modified. 
 * Therefore, validating these values in the constructors should be sufficient to ensure they remain within valid bounds
 */
AForm& AForm::operator=(const AForm& assign) {
	std::cout << this->name << " === AForm assinment operator called ===" << std::endl;
	if (this != &assign) {
		this->isSigned = assign.isSigned;
	}
	return *this;
}

/**
 * Get the name of the form
 */
std::string AForm::getName() const {
	return this->name;
}

/**
 * Get the isSigned status of the form
 */
bool AForm::getIsSigned() const {
	return this->isSigned;
}

/**
 * Get the grade to sign of the form
 */
int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

/**
 * Get the grade to execute of the form
 */
int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

/**
 * Exception for grade too high 
 */
const char* AForm::GradeTooHighException::what() const throw() {
	return  "Grade too high";
}

/**
 * Exception for grade too low
 */
const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}


/**
 * Exception for form not signed
 */
const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed";
}


/**
 * Sign the form
 * @param b
 */
void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= this->gradeToSign) {
		this->isSigned = true;
		std::cout << this->name << " has been signed by " << b.getName() << std::endl;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::setIsSignedTrue() {
	this->isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (!this->getIsSigned()) { 
		throw AForm::FormNotSignedException();
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	} else 
		performAction();
}

void AForm::validateGrade(int grade) const {
    if (grade < 1) {
        throw AForm::GradeTooHighException();
    }
    if (grade > 150) {
        throw AForm::GradeTooLowException();
    }
}

/**
 * Overload the << operator
 */
std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << f.getName() << " is " << (f.getIsSigned() ? "signed " : "not signed ") << "and need a grade to sign of: " << f.getGradeToSign() << " and a grade to execute of: " << f.getGradeToExecute();
	return os;
}