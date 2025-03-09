/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:57:04 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 09:41:29 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "AForm.hpp"

/**
 * Constructor
 */
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , target(target) {
	std::cout << "PresidentialPardonForm " << this->target << " constructor called" << std::endl;
}

/**
 * Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm " << this->target << " destructor called" << std::endl;
}

/**
 * Copy constructor
 * @param src
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.target) {
	std::cout << "PresidentialPardonForm " << this->target << " copy constructor called" << std::endl;
}

/**
 * Assignment operator
 * @param src
 * @return
 */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	std::cout << "PresidentialPardonForm " << this->target << " assignment operator called" << std::endl;
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
 */
void PresidentialPardonForm::performAction() const {
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

