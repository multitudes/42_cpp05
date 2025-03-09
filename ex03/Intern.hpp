/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:42:00 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/21 14:25:05 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

/**
 * Intern class
 * 
 * The code exhibits characteristics of the Factory Method pattern. Here's why:
 * Abstract Factory: The Intern class acts as an abstract factory, 
 * responsible for creating different types of form objects.
 * The private form creation functions (e.g.,createShrubberyForm) 
 * within the Intern class can be considered concrete factories, 
 * each specialized in creating a specific form type.
 * Product: The AForm class represents the abstract product, 
 * while the concrete form objects (e.g., ShrubberyForm, RobotomyForm) 
 * are the concrete products. 
 * Key Elements of Factory Method:
 * Decoupling: The makeForm function decouples the client code (which uses the AForm interface) 
 * from the concrete form creation process.
 * Extensibility: Adding new form types involves creating new concrete factories (private member functions) 
 * within the Intern class, without modifying existing code. 
 * Flexibility: The factory method allows the Intern class to encapsulate the logic 
 * for creating different form types, making it easier to change or replace the creation 
 * process without affecting the client code.
 */
class Intern {
	public:
		// canonical form
		Intern();
		~Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);

		// this is the function that sets apart the intern
		AForm* makeForm(std::string formName, std::string target);

		// exception declaration
		class FormNotFoundException: public std::exception {
			public:
				const char* what() const throw();
		};

		// here are the three function with the correct signature to be included in the 
		// above array
		AForm* createShrubberyForm(std::string target);
		AForm* createRobotomyForm(std::string target);
		AForm* createPresidentialForm(std::string target); 

	private:
		// with this typedef I define a pointer to function type named CreateFormFunc
		// which returns a pointer to an AForm and takes a target
		typedef AForm* (Intern::*CreateFormFunc)(std::string target);
		
		// this is an array of string containing the names of the forms
		static const std::string formNames[3];

		// to avoid the if else forests I use a function pointer structure
		// corresponding to the array with the three names I create an array of three
		// function pointers as defined above
		static const CreateFormFunc formFuncs[3];
};

#endif  // INTERN_HPP_