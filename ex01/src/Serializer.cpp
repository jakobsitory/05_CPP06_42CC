/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:38:04 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 11:55:50 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer(){
}

Serializer::Serializer(Serializer& origin){
	*this = origin;
}

Serializer::~Serializer(){
}

Serializer& Serializer::operator = (Serializer& origin){
	if (this == &origin)
		return *this;
	return *this;
	
}

uintptr_t Serializer::serialize(Data* data){
	return (reinterpret_cast<uintptr_t>(data));
}

Data* Serializer::deserialize(uintptr_t serial){
	return (reinterpret_cast<Data *>(serial));	
}