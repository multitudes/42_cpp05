/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrusa <lbrusa@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:22 by lbrusa            #+#    #+#             */
/*   Updated: 2024/10/23 09:14:48 by lbrusa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"
#include "Form.hpp"

int main() {

	
	Bureaucrat A("alice", 1);
	Bureaucrat B("bob", 150);

	Form F("antimatter-form", 120, 120);
	std::cout << F << std::endl;

	try {
		F.beSigned(B);
		std::cout << F << std::endl;
	} catch (...) {
		std::cout << "exception caught! " << F << std::endl;
	}

	B.signForm(F);


	Form easyF("easyForm", 120, 120);
	// try {
	// 	easyF.beSigned(A);
	// 	easyF.beSigned(A); 
	// } catch (...){
	// 	std::cout << "exception caught! " << F << std::endl;
	// }
	// std::cout << easyF << std::endl;
	A.signForm(easyF);
}
