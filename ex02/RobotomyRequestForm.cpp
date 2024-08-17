/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:20 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 13:57:48 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

/**
 * Constructor
 */
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

/**
 * Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/**
 * Copy constructor
 * @param src
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

/**
 * Assignment operator
 * @param src
 * @return
 */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
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
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	std::cout << ".... drilling noises ...." << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
	}
	else if (executor.getGrade() <= this->getGradeToExecute()) {
		if (rand() % 2) {
			std::cout << this->target << " has been robotomized successfully." << std::endl;
		}
		else {
			std::cout << "Robotomization of " << this->target << " has failed." << std::endl;
		}
	}
	else {
		throw AForm::GradeTooLowException();
	}
}