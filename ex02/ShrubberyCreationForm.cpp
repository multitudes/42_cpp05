/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:44:14 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 11:00:11 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>	
#include <fstream>

/**
 * Constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) , target(target) {
	std::cout << "ShrubberyCreationForm " << this->target << " constructor called" << std::endl;
}

/**
 * Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << this->target << " destructor called" << std::endl;
}

/**
 * Copy constructor
 * @param src
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target) {
	std::cout << "ShrubberyCreationForm " << this->target << " copy constructor called" << std::endl;
}

/**
 * Assignment operator
 * @param src
 * @return a reference to the form
 * Allows the chaining of operators like A = B = C
 * Really assignment AForm::operator=(src) would only assign the isSigned property
 * but in this way is more portable
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	std::cout << "ShrubberyCreationForm " << this->target << " assignment operator called" << std::endl;
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
 * Upon successful execution, the function will create a file with the name of the target
 * and write an ascii tree in it.
 */
void ShrubberyCreationForm::performAction() const {
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file" << std::endl;
		return;
	}
	file << " ============= SHRUBBERY ============= " << std::endl;
	file << "                                          " << std::endl;
	file << "              &&& &&  & &&" << std::endl;
	file << "          && &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "          &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << "       &() &\\/&|()|/&\\/ '%'\\&&\\(\\)" << std::endl;
	file << "      &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "    &&   && & &| &| /& & % ()& /&&" << std::endl;
	file << "     ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "         &&     \\|||" << std::endl;
	file << "                 |||" << std::endl;
	file << "                 |||" << std::endl;
	file << "                 |||" << std::endl;
	file << "           , -=-~  .-^- _" << std::endl;

	file.close();
}