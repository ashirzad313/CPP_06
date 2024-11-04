/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:22:27 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/04 20:24:25 by ashirzad         ###   ########.fr       */
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

#define ft_error -1
#define ft_char 0
#define ft_int 1
#define ft_float 2
#define ft_double 3



class ScalarConverter
{
	private	:
		std::string _input;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		int			_charFlag;
		int			_intFlag;
		int			_floatFlag;
		int			_doubleFlag;
		int			_type;
	public :
		// Orthodox Canonical Form
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &copy);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter(void);


		// methods
		int	isInt(void);
		int	isFloat(void);
		int	isDouble(void);
		int	isChar(void);
		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
		void detect_type(void);
		static void convert(std::string value);

		// getters
		std::string	getInput(void);
		int			getInt(void);
		char		getChar(void);
		float		getFloat(void);
		double		getDouble(void);
		int			getType(void);
		int			getIntFlag(void);
		int			getCharFlag(void);
		int			getFloatFlag(void);
		int			getDoubleFlag(void);
};

std::ostream &operator<<(std::ostream &str, ScalarConverter &converter);

#endif // __SCALARCONVERTER_HPP__ //

