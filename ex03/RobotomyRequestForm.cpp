/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:46:20 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 09:41:46 by lbrusa           ###   ########.fr       */
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
	std::cout << "RobotomyRequestForm " << this->target << " constructor called" << std::endl;
}

/**
 * Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << this->target << " destructor called" << std::endl;
}

/**
 * Copy constructor
 * @param src
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target) {
	std::cout << "RobotomyRequestForm " << this->target << " copy constructor called" << std::endl;
}

/**
 * Assignment operator
 * @param src
 * @return
 */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	std::cout << "RobotomyRequestForm " << this->target << " assignment operator called" << std::endl;
	if (this != &src) {
		AForm::operator=(src);
		this->target = src.target;
	}
	return *this;
}

/**
 * Execute the form
 * @param executor
 * This function is overriding the performAction function from AForm
 * and will throw different exceptions depending on the grade of the executor
 * and if the form is signed or not
 */
void RobotomyRequestForm::performAction() const {
	std::cout << ".... drilling noises ...." << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2) {
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	}
	else {
		std::cout << "Robotomization of " << this->target << " has failed." << std::endl;
	}
}