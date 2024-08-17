/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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
#include "Bureaucrat.hpp"

class Bureaucrat;

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
 */
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif