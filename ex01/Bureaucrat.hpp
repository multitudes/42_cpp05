/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:07:28 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 13:46:41 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "string"
#include "exception"
#include "Form.hpp"

class Form;

/**
 * Bureaucrat class with name and grade
 * This time it has a signForm method which takes a Form as parameter
 * and throws an exception if the bureaucrat's grade is too low
 * to sign the form
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

		void 			signForm(Form& f) const;

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

// overload << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif