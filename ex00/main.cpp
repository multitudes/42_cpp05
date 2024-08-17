/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/08/15 18:03:44 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"

int main() {

	std::cout << "=== Bureaucrats ===" << std::endl;
	try {
		// constructors in try block
		Bureaucrat A("bob", 150);
		Bureaucrat B("alice", 1);
		
		// assignment operator
		B = A;

		// overloading << operator
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		
		A.incrementGrade();
		std::cout << A << std::endl;
	
	// since now B has the same grade as A, decrementing B will throw an exception	
		B.decrementGrade();
		std::cout << B << std::endl;
		
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
