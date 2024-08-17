/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:07:28 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 14:00:24 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "string"
#include "exception"
#include "AForm.hpp"

class AForm;

/**
 * Bureaucrat class with name and grade
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

		void 			signAForm(AForm& f) const;

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