/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:22:27 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/01 18:05:09 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

class ScalarConverter
{
	private	:
		int		_i;
		double	_d;
		float	_f;
		char	_c;
		bool	_isError;
		bool	_isInt;
		bool	_isDouble;
		bool	_isFloat;
		bool	_isChar;
	public :
		// Orthodox Canonical Form
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &copy);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter(void);


		// methods
		int	isInt(std::string value);
		int	isFloat(std::string value);
		int	isDouble(std::string value);
		int	isChar(std::string value);
		void detect_type(std::string value);
		static void convert(std::string value);

		// to methods
		void	toChar();
		void	toInt();
		void	toFloat(std::string value);
		void	toDouble(std::string value);

		// object error

		class CharError : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
		class IntError : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
		class DoubleError : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
		class FloatError : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

};

#endif // __SCALARCONVERTER_HPP__ //

