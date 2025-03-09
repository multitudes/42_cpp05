/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:07:28 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/22 17:41:35 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include "string"
#include "exception"

class AForm;

/**
 * Bureaucrat class in Orthodox Canonical Form with name and grade
 * 
 * The exceptions need to be defined in the class since in the 
 * subject are declared like Bureaucrat::GradeTooHighException etc.
 * I cannot use define them outside the class. 
 */
class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& assign);
		
		// getters
		std::string 	getName() const;
		int 			getGrade() const;
		void 			incrementGrade();
		void 			decrementGrade();
		void			validateGrade(int grade);
		void 			signForm(AForm& f) const;
		
		void 			executeForm(AForm const & form) const; 

		// exceptions
		class GradeTooHighException: public std::exception {
			public:
                const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception {
			public:
                const char* what() const throw();
		};

	private:
		const std::string name;
		int grade;
};

// overload << operator to print my bureaucrat in a sensible way
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif