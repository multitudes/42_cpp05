/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:01:00 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/16 11:28:19 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "string"
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

/**
 * Abstract Form class with name, isSigned, gradeToSign and gradeToExecute
 */
class AForm {

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& copy);
		AForm& operator=(const AForm& assign);

		// getters
		std::string 	getName() const;
		bool 			getIsSigned() const;
		int 			getGradeToSign() const;
		int 			getGradeToExecute() const;

		void			beSigned(const Bureaucrat& b);
		void 			setIsSignedTrue();

		// I implemented it this way. execute does the checks and then calls performAction
		void			execute(const Bureaucrat& executor) const;
		
		// this makes my AForm abstract and will be implemented
		// in the derived classes - the = 0 makes it pure virtual
		// an abstract class cannot be instantiated
		virtual void 	performAction() const = 0;

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

		class FormNotSignedException: public std::exception {
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
 */
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif