/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:57:04 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 13:57:11 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "AForm.hpp"

/**
 * Constructor
 */
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

/**
 * Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/**
 * Copy constructor
 * @param src
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

/**
 * Assignment operator
 * @param src
 * @return
 */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &src) {
		AForm::operator=(src);
		this->target = src.target;
	}
	return *this;
}

/**
 * Execute the form
 * @param executor
 * This function is overriding the execute function from AForm
 * and will throw different exceptions depending on the grade of the executor
 * and if the form is signed or not
 */
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (this->getIsSigned() == true && executor.getGrade() <= this->getGradeToExecute()) {
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
	else if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
	} else if (executor.getGrade() <= this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
}

