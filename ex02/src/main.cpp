/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:43:48 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 16:18:38 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#define TEXT_NOFORMAT	"\e[0m"
#define TEXT_BOLD		"\e[1m"
#define TEXT_UNDERLINE	"\e[4m"

#define COLOR_STANDARD	"\033[0m"
#define	COLOR_ERROR		"\033[31m"
#define COLOR_WARNING	"\033[33m"
#define COLOR_SUCCESS	"\033[92m"
#define COLOR_FOCUS		"\e[35m"

Base*	generate(){
	std::srand(std::time(NULL));
	int num = rand() % 3;
	if (num == 0)
		return (new A());
	if (num == 1)
		return (new B());
	return (new C());
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << TEXT_BOLD << "Type A" << TEXT_NOFORMAT;
	else if (dynamic_cast<B*>(p))
		std::cout << TEXT_BOLD << "Type B" << TEXT_NOFORMAT;
	else if (dynamic_cast<C*>(p))
		std::cout << TEXT_BOLD << "Type C" << TEXT_NOFORMAT;
	else
		std::cout << COLOR_ERROR << "No type";
	std::cout << " identified" << std::endl;
}

void	identify(Base& p){
	Base tmp;

	try	{
		tmp = dynamic_cast<A&>(p);
		std::cout << TEXT_BOLD << "Type A" << TEXT_NOFORMAT << " identified" << std::endl;
	}
	catch(const std::exception& e) {
	}
	try	{
		tmp = dynamic_cast<B&>(p);
		std::cout << TEXT_BOLD << "Type B" << TEXT_NOFORMAT << " identified" << std::endl;
	}
	catch(const std::exception& e) {
	}
	try	{
		tmp = dynamic_cast<C&>(p);
		std::cout << TEXT_BOLD << "Type C" << TEXT_NOFORMAT << " identified" << std::endl;
	}
	catch(const std::exception& e) {
	}	
}


int main (){
	std::cout << "Welcome to the Type identifier!" << std::endl;
	std::cout << "To exit enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << std::endl;
	std::cout << TEXT_BOLD << "Press Enter" << TEXT_NOFORMAT << " to start simulation" << std::endl;
	std::string input = "";
	std::getline(std::cin, input);
	while(input != "EXIT"){
		
		std::cout << "Press " << TEXT_BOLD << "Enter" << TEXT_NOFORMAT << " to create a random type";
		input = "";
		std::getline(std::cin, input);
		Base *unknown = generate();
		
		std::cout  << std::endl <<  "Press " << TEXT_BOLD << "Enter" << TEXT_NOFORMAT<< " to identify unknown object";
		input = "";
		std::getline(std::cin, input);
		identify(unknown);
		
		std::cout  << std::endl << "Press " << TEXT_BOLD << "Enter" << TEXT_NOFORMAT << " to identify unknown type by its pointer";
		input = "";
		std::getline(std::cin, input);
		identify(*unknown);

		std::cout << std::endl << "Simulation done" << std::endl;
		std::cout << "To exit enter EXIT" << std::endl;
		std::cout << "To restart enter RESTART" << std::endl;
		while (input != "RESTART" && input != "EXIT")
			std::getline(std::cin, input);
		std::cout << std::endl;
	} 
	return 0;
}