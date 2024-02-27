/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:31:42 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 12:14:02 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(/* args */){
}

Data::Data(Data& origin){
	*this = origin;
}

Data& Data::operator = (Data& origin){
	if (this == &origin)
		return *this;
	this->_name = origin._name;
	this->_phone = origin._phone;
	this->_address = origin._address;
	return *this;
}

Data::~Data(){
}

std::ostream& operator<< (std::ostream& os, const Data& data){
	os << "Name:\t\t" << TEXT_BOLD << data._name << TEXT_NOFORMAT << std::endl
		<< "Phone:\t\t" << TEXT_BOLD << std::boolalpha <<  data._phone << TEXT_NOFORMAT << std::endl
		<< "Address:\t" << TEXT_BOLD <<  data._address << TEXT_NOFORMAT << std::endl
		<< "Mem address:\t" << TEXT_BOLD << &data << TEXT_NOFORMAT << std::endl;
	return os;
}