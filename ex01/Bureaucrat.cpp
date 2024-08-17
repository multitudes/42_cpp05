/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:07:03 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 13:28:19 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "exception"
#include "Form.hpp"
#include "Bureaucrat.hpp"

/**
 * Default constructor
 */
Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "=== Bureaucrat def constructor called ===" << std::endl;
}

/**
 * Parameterized constructor
 * @param name
 * @param grade
 */
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "=== Bureaucrat constructor called ===" << std::endl;
}

/**
 * Destructor
 */
Bureaucrat::~Bureaucrat() {
	std::cout << "=== Bureaucrat destructor called ===" << std::endl;
}

/**
 * Copy constructor
 * @param copy
 */
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade) {
	std::cout << "=== Bureaucrat copy constructor called ===" << std::endl;
}

/**
 * Assignment operator
 * @param assign
 * @return
 */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assign) {
	std::cout << "=== Bureaucrat assignment operator called ===" << std::endl;
	if (this != &assign) {
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

void Bureaucrat::signForm(Form& f) const {
	if (f.getGradeToSign() >= this->grade){
		std::cout << this->name << " signed " << f.getName() << std::endl;
		f.setIsSignedTrue();
	} else {
		std::cout << this->name << " couldn’t sign " << f.getName() << " because " << "unsufficient privileges!" << std::endl;
	} 
}

/**
 * throw an exception if the grade is too low
 */
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

/**
 * throw an exception if the grade is too high
 */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
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
	if (this->grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

/**
 * Decrement the grade of the bureaucrat
 */
void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}
