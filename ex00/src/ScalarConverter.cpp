/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:10:06 by jschott           #+#    #+#             */
/*   Updated: 2024/02/27 11:40:49 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(ScalarConverter& origin){
	*this = origin;
}

ScalarConverter& ScalarConverter::operator = (ScalarConverter& origin){
	if (this == &origin)
		return *this;
	this->_charval = origin._charval;
	this->_intval = origin._intval;
	this->_floatval = origin._floatval;
	this->_doubleval = origin._doubleval;
	return *this;
	
}

ScalarConverter::~ScalarConverter(){
}

void	ScalarConverter::convert(const char* input){
	ScalarConverter 	tmp_scalar;
	std::string			input_str = input;
	char				*end_double = NULL;
	char				*end_float = NULL;
	char				*end_int = NULL;
	if (strlen(input) == 1){
		if (input[0] < '0' || input[0] > '9')
			tmp_scalar._charval = input[0];
		else
			tmp_scalar._charval = input[0] - '0';
		tmp_scalar._intval = static_cast<int>(tmp_scalar._charval);
		tmp_scalar._floatval = static_cast<float>(tmp_scalar._charval);
		tmp_scalar._doubleval = static_cast<double>(tmp_scalar._charval);
	
		std::cout << "char:\t" << TEXT_BOLD;
		if (!isprint(tmp_scalar._charval))
			std::cout << "Non displayable";
		else
			std::cout << "\'" << tmp_scalar._charval << "\'";
		std::cout << TEXT_NOFORMAT << std::endl;
	
		std::cout << "int:\t" << TEXT_BOLD
		<< tmp_scalar._intval	
		<< TEXT_NOFORMAT << std::endl;	
	
		std::cout << "float:\t" << std::fixed << std::setprecision(1) << TEXT_BOLD
		<< tmp_scalar._floatval << "f"
		<< TEXT_NOFORMAT << std::endl;
	
		std::cout << "double:\t" << TEXT_BOLD
		<< tmp_scalar._doubleval
		<< TEXT_NOFORMAT << std::endl;
	}
	else {
		tmp_scalar._intval = std::strtol(input, &end_int, 10);
		tmp_scalar._floatval = std::strtof(input, &end_float);
		tmp_scalar._doubleval = std::strtod(input, &end_double);
		tmp_scalar._charval = static_cast<char>(tmp_scalar._intval);
		
		std::cout << "int:\t"  << tmp_scalar._intval << "\t"	<< end_int << std::endl;
		std::cout << "float:\t"  << tmp_scalar._floatval << "\t"	<< end_float << std::endl;
		std::cout << "double:\t"  << tmp_scalar._doubleval << "\t"	<< end_double << std::endl;

		
		std::cout << "char:\t" << TEXT_BOLD;
		if (!isascii(tmp_scalar._doubleval) || std::isnan(tmp_scalar._floatval)
			|| (!end_double && (!strcmp(end_double, "f") ||  end_double == end_int)))
			std::cout << "impossible";
		else if (!isprint(tmp_scalar._charval))
			std::cout << "Non displayable";
		else
			std::cout << "\'" << tmp_scalar._charval << "\'";
		std::cout << TEXT_NOFORMAT << std::endl;
		
		std::cout << "int:\t" << TEXT_BOLD;
		if (tmp_scalar._doubleval < INT_MIN || tmp_scalar._doubleval > INT_MAX
			|| (std::isnan(tmp_scalar._floatval))
			|| (!end_double && !strcmp(end_double, "f")))
			std::cout << "impossible";
		else
			std::cout<< tmp_scalar._intval;	
		std::cout << TEXT_NOFORMAT << std::endl;	
		
		if (static_cast<double>(tmp_scalar._intval) == tmp_scalar._doubleval)
			std::cout << std::fixed << std::setprecision(1);
		else
			std::cout << std::fixed << std::setprecision(strlen(end_int) - strlen(end_double) - 1);
		
		std::cout << "float:\t" << TEXT_BOLD ;
		if (!end_float && !strcmp(end_float, "f"))
			std::cout << "impossible";
		else
			std::cout << tmp_scalar._floatval << "f";
		std::cout << TEXT_NOFORMAT << std::endl;
		
		std::cout << "double:\t" << TEXT_BOLD;
		if (!end_double && !strcmp(end_double, "f"))
			std::cout << "impossible";
		else
			std::cout<< tmp_scalar._doubleval;	
		std::cout << TEXT_NOFORMAT << std::endl;
	}
}
