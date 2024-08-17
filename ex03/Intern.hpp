/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:42:00 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 14:01:10 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

/**
 * Intern class
 */
class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern& operator=(const Intern& src);

		AForm* makeForm(std::string formName, std::string target);

		class FormNotFoundException: public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		static const std::string formNames[3];
		typedef AForm* (Intern::*CreateFormFunc)(std::string target);
		static const CreateFormFunc formFuncs[3];

		AForm* createShrubberyForm(std::string target);
		AForm* createRobotomyForm(std::string target);
		AForm* createPresidentialForm(std::string target); 
};

#endif  // INTERN_HPP_