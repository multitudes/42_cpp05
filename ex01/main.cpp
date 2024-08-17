/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/16 11:40:14 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"
#include "Form.hpp"

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
	Form F("form", 120, 120);
	std::cout << F << std::endl;
	try {
	F.beSigned(A);

	std::cout << F << std::endl;
	} catch (...) {
		std::cout << "exception caught! " << F << std::endl;
	}

	A.signForm(F);
	Form easyF("easyForm", 150, 150);
	try {
		F.beSigned(A);
	} catch (...){
		std::cout << "exception caught! " << F << std::endl;
	}
	easyF.beSigned(A); 
	std::cout << easyF << std::endl;
	A.signForm(easyF);
}
