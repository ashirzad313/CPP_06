/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:22:27 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/02 16:41:43 by ashirzad         ###   ########.fr       */
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
#define ft_char 1
#define ft_int 2
#define ft_float 3
#define ft_double 4



class ScalarConverter
{
	private	:
		std::string _input;
		int			_i;
		int			_intFlag;
		double		_d;
		int			_doubleFlag;
		float		_f;
		int			_floatFlag;
		char		_c;
		int			_charFlag;
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
		int		getInt(void);
		char	getChar(void);
		float	getFloat(void);
		double	getDouble(void);
		int		getIntFlag(void);
		int		getCharFlag(void);
		int		getFloatFlag(void);
		int		getDoubleFlag(void);


		// object error

		class CharError : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
		class CharError2 : public std::exception
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

std::ostream &operator<<(std::ostream &str, ScalarConverter &converter);

#endif // __SCALARCONVERTER_HPP__ //

