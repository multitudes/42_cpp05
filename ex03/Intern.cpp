/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:41:45 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 12:46:28 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/**
 * Initialize the static arrays
 * This works even if they are declared as private!
 */
const std::string Intern::formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

/**
 * Initialize the static array of function pointers
 * This will be used to call the correct function to create the form
 */
const Intern::CreateFormFunc Intern::formFuncs[3] = {
	&Intern::createShrubberyForm,
	&Intern::createRobotomyForm,
	&Intern::createPresidentialForm
};

/**
 * Default constructor
 */
Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

/**
 * Copy constructor
 * @param copy
 */
Intern::Intern(const Intern& copy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}
	
/**
 * Destructor
 */
Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

/**
 * Assignment operator
 */
Intern& Intern::operator=(const Intern& src) {
	std::cout << "Intern assignment operator called" << std::endl;
	if (this != &src) {
	}
	return *this;
}

/**
 * Create a form public function
 * @param formName
 * @param target
 * 
 * @return AForm*
 * Takes a form name and a target and creates the form
 * I decided to throw an exception if the form is not found. The subject 
 * asks to print an error message and using the make function to return NULL
 * is also a valid approach but then the caller should guard from null values
 * I think the point of this exercise is to learn how to throw exceptions...
 */
AForm* Intern::makeForm(std::string formName, std::string target) {
	std::cout << "Intern creates " << formName << std::endl;
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			return (this->*formFuncs[i])(target);
		}
	}
	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

/**
 * Create a shrubbery form
 */
AForm* Intern::createShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

/**
 * Create a robotomy form
 */
AForm* Intern::createRobotomyForm(std::string target) {
	return new RobotomyRequestForm(target);
}

/**
 * Create a presidential form
 */
AForm* Intern::createPresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}
