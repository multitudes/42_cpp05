/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 08:44:41 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"

/**
 * Main function with test cases
 */
int main() {

	std::cout << "=== Bureaucrats start ===" << std::endl;
	try {
		// constructors in try block because they can throw!
		Bureaucrat A("alice", 1);
		Bureaucrat B("bob", 150);
		
		// throws exception
		// A.incrementGrade();

		// assignment operator
		A = B;

		// overloading << operator
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		
		A.incrementGrade();
		std::cout << A << std::endl;
	
	// since now B has the same grade as A, decrementing B will throw an exception	
		// B.decrementGrade();

		Bureaucrat C("charlie", 1);
	//  incrementing C will throw an exception
		// C.incrementGrade();
	
	// copy constructor
		std::cout << "== copy constructor D = A ==" << std::endl;
		Bureaucrat D(A);
		std::cout << D << std::endl;
		
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
}
