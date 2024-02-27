/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:19:08 by jschott           #+#    #+#             */
/*   Updated: 2024/02/27 11:47:33 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main (int argc, char **argv){

	if (argc < 2)
		return 0;
	for (int i = 1; i < argc; i++)
		ScalarConverter::convert(argv[i]);
	return 0;
}
