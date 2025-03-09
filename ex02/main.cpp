/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 10:27:20 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {

	std::cout << "=== Bureaucrats ===" << std::endl;
	Bureaucrat A("alice", 145);
	Bureaucrat B("bob", 137);
	

	AForm* P = new PresidentialPardonForm("wanna-go-home");

	std::cout << *P << std::endl;
	try {
		(*P).beSigned(B);
		std::cout << *P << std::endl;
	} catch (...) {
		std::cout << "exception caught! " << *P << std::endl;
	}

	A.signForm(*P);
	// here melvin is the target!
	PresidentialPardonForm presid("melvin");
	try {
		presid.beSigned(B);
	} catch (...){
		std::cout << "exception caught! " << presid << std::endl;
	}
	std::cout << presid << std::endl;
	try {
		presid.beSigned(A); 
	} catch (...) {
		std::cout << "exception caught! " << presid << std::endl;
	}
	std::cout << presid << std::endl;
	A.signForm(presid);

	AForm* R = new RobotomyRequestForm("cathy");
	std::cout << *R << std::endl;
	try {
		(*R).beSigned(A);
	} catch (...) {
		std::cout << "exception caught! " << *R << std::endl;
	}

//  need a grade to sign of: 145 and a grade to execute of: 137
	Bureaucrat A_schrub("alice", 145);
	Bureaucrat B_schrub("bob", 137);
	AForm* S = new ShrubberyCreationForm("shrubby");
	std::cout << *S << std::endl;
	try {
		(*S).beSigned(A_schrub);
		(*S).execute(A_schrub);
	} catch (const AForm::GradeTooLowException& e ) {
		std::cout << "exception caught by form! " << e.what() << std::endl;
	}

	B_schrub.executeForm(*S);
	
	
	Bureaucrat Powerful("powerful", 1);	
	Powerful.executeForm(*P);
	Powerful.executeForm(*R);
	// try {
	// 	(*P).execute(Powerful);
	// 	(*R).execute(Powerful);
	// 	(presid).execute(Powerful);
	// 	(*S).beSigned(Powerful);
	// 	(*S).execute(Powerful);
	// } catch (const AForm::FormNotSignedException& e) {
	// 	std::cerr << "-------------------> Exception caught: " << e.what() << std::endl;
	
	// } catch (...) {
	// 	std::cout << "exception caught! " << *S << std::endl;
	// }


	delete P;
	delete R;
	delete S;
	return 0;
}