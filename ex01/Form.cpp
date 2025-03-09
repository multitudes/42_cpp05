/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:00:34 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 09:24:23 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

/**
 * Default constructor
 */
Form::Form() : name("default form"), isSigned(false), gradeToSign(150), gradeToExecute(1) {
	std::cout << this->name << " === Form def constructor called ===" << std::endl;
}

/**
 * Parameterized constructor
 * @param name
 * @param gradeToSign
 * @param gradeToExecute
 * 
 * Will throw if gradeToSign or gradeToExecute is out of bounds
 */
Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << this->name << " === Form constructor called ===" << std::endl;
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

/**
 * Destructor
 */
Form::~Form() {
	std::cout << this->name << " === Form destructor called ===" << std::endl;
}

/**
 * Copy constructor
 * @param copy
 * 
 * Name is not copied since it is a const member
 * same for the other const members
 */
Form::Form(const Form& copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
	std::cout << this->name << " === Form copy constructor called ===" << std::endl;
}

/**
 * Assignment operator
 * 
 * Name is not assigned since it is a const member
 * same for the other const members
 */
Form& Form::operator=(const Form& assign) {
	std::cout << this->name << " === Form assinment operator called ===" << std::endl;
	if (this != &assign) {
		this->isSigned = assign.isSigned;
	}
	return *this;
}

/**
 * Get the name of the form
 */
std::string Form::getName() const {
	return this->name;
}

/**
 * Get the isSigned status of the form
 */
bool Form::getIsSigned() const {
	return this->isSigned;
}

/**
 * Get the grade to sign of the form
 */
int Form::getGradeToSign() const {
	return this->gradeToSign;
}

/**
 * Get the grade to execute of the form
 */
int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

/**
 * Exception for grade too high 
 */
const char* Form::GradeTooHighException::what() const throw() {
	return  "Form exception: Grade too high";
}

/**
 * Exception for grade too low
 */
const char* Form::GradeTooLowException::what() const throw() {
	return "Form exception: Grade too low";
}

/**
 * Sign the form
 * @param b (bureaucrat)
 */
void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= this->gradeToSign) {
		this->isSigned = true;
		std::cout << this->name << " has been signed by " << b.getName() << std::endl;
	} else {
		throw Form::GradeTooLowException();
	}
}

void Form::setIsSignedTrue() {
	this->isSigned = true;
}

void Form::validateGrade(int grade) const {
    if (grade < 1) {
        throw Form::GradeTooHighException();
    }
    if (grade > 150) {
        throw Form::GradeTooLowException();
    }
}
/**
 * Overload the << operator
 */
std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << f.getName() << " is " << (f.getIsSigned() ? "signed " : "not signed ") << "and need a grade to sign of: " 
	<< f.getGradeToSign() << " and a grade to execute of: " << f.getGradeToExecute();
	return os;
}
