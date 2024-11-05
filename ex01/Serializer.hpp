/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:54:03 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/05 10:33:22 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <iostream>
#include <iomanip>
#include "Data.hpp"

class Serializer
{
	public :
		Serializer(void);
		Serializer(Serializer &copy);
		Serializer &operator=(Serializer &other);
		~Serializer(void);

		//static methods
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif // __SERIALIZER_HPP__ //
