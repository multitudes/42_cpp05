/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:44:14 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 14:07:01 by lbrusa           ###   ########.fr       */
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
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

/**
 * Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/**
 * Copy constructor
 * @param src
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

/**
 * Assignment operator
 * @param src
 * @return
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
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
 * and if the form is signed or not. 
 */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
	}
	else if (executor.getGrade() <= this->getGradeToExecute()) {
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
	else {
		throw AForm::GradeTooLowException();
	}
}