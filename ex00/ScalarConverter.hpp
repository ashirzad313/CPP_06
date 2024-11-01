/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:22:27 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/01 14:36:25 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class ScalarConverter
{
	private	:
		std::string _value;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
	public :
		// Orthodox Canonical Form
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &copy);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter(void);


		// methods
		static std::string	detect_type(std::string value);
		static void convert(std::string value);

		// object error

		class InvalidType : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

};

#endif // __SCALARCONVERTER_HPP__ //

