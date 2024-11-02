/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:26:40 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/02 17:07:15 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Orthodox Canonical Form

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(ScalarConverter &copy){*this = copy;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter(void){}

// methods

int	count_decimals(std::string value)
{
	int	count = 0;

	for (int i = 0; i < (int)value.length(); i++)
	{
		if (value[i] == '.')
			count += 1;
		else if (count)
			count += 1;
	}
	if (count > 1)
		count -= 1;
	return (count);
}

void	ScalarConverter::toInt()
{
	if (this->_type == ft_error)
	{
		this->_intFlag = 1;
		return ;
	}
	if (this->_type == ft_int)
	{
		this->_intFlag = 0;	
		return ;
	}
	else if (this->_type == ft_char)
		this->_i = (int)this->_c;
	else if (this->_type == ft_double)
		this->_i = (int)this->_d;
	else if (this->_type == ft_float)
		this->_i = (int)this->_f;
	this->_intFlag = 0;
}

void	ScalarConverter::toDouble(void)
{
	if (this->_type == ft_error)
	{
		this->_doubleFlag = 1;
		return ;
	}
	if (this->_type == ft_double)
	{
		this->_doubleFlag = 0;
		return ;
	}
	else if (this->_type == ft_int)
		this->_d = (double)this->_i;
	else if (this->_type == ft_char)
		this->_d = (double)this->_c;
	else if (this->_type == ft_float)
		this->_d = (double)this->_f;
	this->_doubleFlag = 0;
}

void	ScalarConverter::toFloat()
{
	if (this->_type == ft_error)
	{
		this->_floatFlag = 1;
		return ;
	}
	else if (this->_type == ft_float)
	{
		this->_floatFlag = 0;
		return ;
	}
	else if (this->_type == ft_int)
		this->_f = (float)this->_i;
	else if (this->_type == ft_char)
		this->_f = (float)this->_c;
	else if (this->_type == ft_double)
		this->_f = (float)this->_d;
	this->_floatFlag = 0;
}

void	ScalarConverter::toChar()
{
	int	n = 32;
	int types[3] = {ft_int, ft_float, ft_double};
	int values[3] = {this->_i, (int)this->_f, (int)this->_d};
	if (this->_type == ft_error)
	{
		this->_charFlag = 1;
		return ;
	}
	for (int i = 0; i < 3; i++)
	{
		if (this->_type == types[i])
		{
			n = values[i];
			if ((n >= 0 && n <= 31) || n == 127)
			{
				this->_charFlag = 2;
				return ;
			}
			else if (n < 32 || n > 126)
			{
				this->_charFlag = 1;
				return ;
			}
			this->_c = (char)n;
			this->_charFlag = 0;
			return ;
		}
	}
	this->_charFlag = 0;
}

void ScalarConverter::detect_type()
{
	if (this->isInt() != -1)
	{
		this->_i = std::stoi(this->_input);
		this->_type = ft_int;
	}
	else if (this->isDouble() != -1)
	{
		this->_d = std::stod(this->_input);
		this->_type = ft_double;
	}
	else if (this->isFloat() != -1)
	{
		this->_f = std::stof(this->_input);
		this->_type = ft_float;
	}
	else if (this->isChar() != -1)
	{
		this->_c = (char)this->_input[0];
		this->_type = ft_char;
	}
	else
		this->_type = ft_error;
}

void	ScalarConverter::convert(std::string value)
{
	ScalarConverter converter;

	converter._input = value;
	converter.detect_type();
	
	converter.toChar();
	converter.toInt();
	converter.toFloat();
	converter.toDouble();

	std::cout << converter << std::endl;
}

// object errors

const char *ScalarConverter::CharError::what(void) const throw()
{
	return ("char : impossible");
}

const char *ScalarConverter::CharError2::what(void) const throw()
{
	return ("char : Non displayable");
}

const char *ScalarConverter::IntError::what(void) const throw()
{
	return ("int : impossible");
}

const char *ScalarConverter::FloatError::what(void) const throw()
{
	return ("float : nanf");
}

const char *ScalarConverter::DoubleError::what(void) const throw()
{
	return ("double : nan");
}

// setter


std::ostream &operator<<(std::ostream &str, ScalarConverter &converter)
{
	std::string char_str;
	std::string int_str;
	std::string float_str;
	std::string double_str;

	if (converter.getCharFlag() == 0)
		char_str = "'" + std::string(1, converter.getChar()) + "'";
	else if (converter.getCharFlag() == 1)
		char_str = "impossible" ;
	else if (converter.getCharFlag() == 2)
		char_str = "Non displayable" ;

	if (converter.getIntFlag() == 0)
		int_str = std::to_string(converter.getInt());
	else
		int_str = "impossible";
	
	if (converter.getFloatFlag() == 0)
		float_str = std::to_string(converter.getFloat()) + "f";
	else
		float_str = "nanf";
	
	if (converter.getDoubleFlag() == 0)
		double_str = std::to_string(converter.getDouble());
	else
		double_str = "nan";
	
	str << "char : " << char_str << std::endl \
	<< "int : " << int_str << std::endl \
	<< "float : " << float_str << std::endl \
	<< "double : " << double_str; 
	return (str);
}

