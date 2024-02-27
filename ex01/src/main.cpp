/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:50:57 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 16:20:08 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h> 

int main (void){

	std::cout << "Welcome to the serializer simulator!" << std::endl;
	std::cout << "To exit enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << std::endl;
	std::cout << TEXT_BOLD << "Press Enter" << TEXT_NOFORMAT << " to start simulation" << std::endl;
	std::string input = "";
	std::getline(std::cin, input);
	while (input != "EXIT"){
		Data *data = new Data();
		std::cout << std::endl << "Please enter Data to serialize" << std::endl;
		std::cout << "Name:\t\t";
		while (data->_name == "")
			std::getline(std::cin, data->_name);
		std::cout << "Phone:\t\t";
		while (data->_phone == "")
			std::getline(std::cin, data->_phone);
		std::cout << "Address:\t";
		while (data->_address == "")
			std::getline(std::cin, data->_address);
		
		std::cout << std::endl << "Press Enter to serialize Data" << std::endl;
		input = "";
		std::getline(std::cin, input);
		uintptr_t serial = Serializer::serialize(data);
		std::cout << std::endl << COLOR_SUCCESS << "SUCCESS!" << COLOR_STANDARD << std::endl
		<< "Result:\t" << TEXT_BOLD << serial  << TEXT_NOFORMAT << std::endl;
		
		std::cout << std::endl << "Press Enter to deserialize Data" << std::endl;
		input = "";
		std::getline(std::cin, input);
		std::cout << std::endl << COLOR_SUCCESS << "SUCCESS!" << COLOR_STANDARD << std::endl
		<< "ORIGINAL:" <<std::endl << *data << std::endl << std::endl
		<< "DESERIALIZED:\t" <<std::endl << *Serializer::deserialize(serial) << std::endl;

		std::cout << std::endl << "Simulation done" << std::endl;
		std::cout << "To exit enter EXIT" << std::endl;
		std::cout << "To restart enter RESTART" << std::endl;
		input = "";
		while (input != "RESTART" && input != "EXIT")
			std::getline(std::cin, input);
	}
	return 0;
}