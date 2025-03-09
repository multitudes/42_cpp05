/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:01:00 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/21 12:28:16 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "string"
#include "Bureaucrat.hpp"

class Bureaucrat;

/**
 * Form class in Orthodox Canonical Form with name, 
 * isSigned, gradeToSign and gradeToExecute.
 * 
 * The exceptions need to be defined in the class since in the 
 * subject are declared like Form::GradeTooHighException etc.
 * I cannot use define them outside the class. It would be a nice refactor
 * to have a separate class for those to reuse in the Bureaucrat class as well
 * but not allowed in the subject.
 */
class Form {

	public:

	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form& copy);
	Form& operator=(const Form& assign);

	// getters
	std::string 	getName() const;
	bool 			getIsSigned() const;
	int 			getGradeToSign() const;
	int 			getGradeToExecute() const;

	void			beSigned(const Bureaucrat& b);
	void 			setIsSignedTrue();
	
	// utility function
	void 			validateGrade(int grade) const;

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
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
};

/**
 * Output stream operator overload - forward declaration
 * prints the form in a sensible way
 */
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif