/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:37:22 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 12:13:02 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h> 
#include <string>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
	Serializer(Serializer& origin);
	Serializer& operator = (Serializer& origin);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif