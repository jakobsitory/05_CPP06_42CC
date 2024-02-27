/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:58:33 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 13:42:43 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

#define TEXT_NOFORMAT	"\e[0m"
#define TEXT_BOLD		"\e[1m"
#define TEXT_UNDERLINE	"\e[4m"

#define COLOR_STANDARD	"\033[0m"
#define	COLOR_ERROR		"\033[31m"
#define COLOR_WARNING	"\033[33m"
#define COLOR_SUCCESS	"\033[92m"
#define COLOR_FOCUS		"\e[35m"

class ScalarConverter
{
private:
	char	_charval;
	int		_intval;
	float	_floatval;
	double	_doubleval;

	ScalarConverter();
	ScalarConverter(ScalarConverter& origin);
	ScalarConverter& operator = (ScalarConverter& origin);
	~ScalarConverter();
	
public:
	static void	convert(const char* input);

	
	class TypeConversionException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("ScalarConverter::TypeConversionException");
			}
	};
};

#endif
