/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/17 13:05:06 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main() {

	Bureaucrat A("bob", 150);
	Bureaucrat B("alice", 1);
	std::cout << "=== Bureaucrats ===" << std::endl;
	try {
		// constructors in try block
		
		// assignment operator
		B = A;

		// overloading << operator
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		
		A.incrementGrade();
		std::cout << A << std::endl;
	
	// since now B has the same grade as A, decrementing B will throw an exception	
		// B.decrementGrade();
		// std::cout << B << std::endl;
		
	// } catch (const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// } catch (const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// } catch (const std::exception& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	AForm* P = new PresidentialPardonForm("home");

	std::cout << *P << std::endl;
	try {
	(*P).beSigned(A);

	std::cout << *P << std::endl;
	} catch (...) {
		std::cout << "exception caught! " << *P << std::endl;
	}

	A.signAForm(*P);
	PresidentialPardonForm presid("melvin");
	try {
		presid.beSigned(A);
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
	A.signAForm(presid);

	AForm* R = new RobotomyRequestForm("cathy");
	std::cout << *R << std::endl;
	try {
	(*R).beSigned(A);
	} catch (...) {
		std::cout << "exception caught! " << *R << std::endl;
	}

	AForm* S = new ShrubberyCreationForm("shrubby");
	std::cout << *S << std::endl;
	try {
	(*S).beSigned(A);
	} catch (...) {
		std::cout << "exception caught! " << *S << std::endl;
	}
	
	Bureaucrat Powerful("powerful", 1);	
	try {
		(*P).execute(Powerful);
		(*R).execute(Powerful);
		(presid).execute(Powerful);
		(*S).beSigned(Powerful);
		(*S).execute(Powerful);
	} catch (const AForm::FormNotSignedException& e) {
		std::cerr << "-------------------> Exception caught: " << e.what() << std::endl;
	
	} catch (...) {
		std::cout << "exception caught! " << *S << std::endl;
	}

	// test the intern
	Intern intern;
	AForm* shrub = intern.makeForm("shrubbery creation", "home");
	std::cout << *shrub << std::endl;
	AForm* rob = intern.makeForm("robotomy request", "bender");
	std::cout << *rob << std::endl;
	AForm* pres = intern.makeForm("presidential pardon", "melvin");
	std::cout << *pres << std::endl;
	AForm* fail = NULL;
	try {
		fail = intern.makeForm("fail", "fail");
		//use fail  -- two patterns either use fail form in the block and delete it here
		// or check for null pointer outside and delete there... or use smartpointers :)
		// delete fail;
	} catch (const Intern::FormNotFoundException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	if (fail) {
		std::cout << *fail << std::endl;
		delete fail;
	}
	std::cout << "=== Deleting ===" << std::endl;
	delete shrub;
	delete rob;
	delete pres;

	delete P;
	delete R;
	delete S;
	return 0;
}