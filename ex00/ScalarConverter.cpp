/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:26:40 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/04 20:42:24 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Orthodox Canonical Form

ScalarConverter::ScalarConverter(void): _charFlag(0), _intFlag(0), _floatFlag(0), _doubleFlag(0){}

ScalarConverter::ScalarConverter(ScalarConverter &copy){*this = copy;}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter(void){}

// methods

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

	void (ScalarConverter::*complain[4])(void) = {&ScalarConverter::toChar, &ScalarConverter::toInt, \
		&ScalarConverter::toFloat, &ScalarConverter::toDouble};
	converter._input = value;
	converter.detect_type();

	for (int i = 0; i < 4; i++)
	{
		if (i != converter._type)
			(converter.*complain[i])();
	}
	std::cout << converter << std::endl;
}

int	ScalarConverter::isInt()
{
	for (int i = 0; i < (int)this->_input.length(); i++)
	{
		if (this->_input[i] < '0' || this->_input[i] > '9')
			return (-1);
	}
	return (0);
}

int	ScalarConverter::isDouble()
{
	int dot_count = std::count(this->_input.begin(), this->_input.end(), '.');
	if (dot_count != 1)
		return (-1);
	for (int i = 0; i < (int)this->_input.length(); i++)
	{
		if ((this->_input[i] < '0' || this->_input[i] > '9') && this->_input[i] != '.')
			return (-1);
	}
	return (0);
}

int	ScalarConverter::isFloat()
{
	int dot_count = std::count(this->_input.begin(), this->_input.end(), '.');
	int	f_count = std::count(this->_input.begin(), this->_input.end(), 'f');
	if (dot_count != 1 || f_count > 1)
		return (-1);
	for (int i = 0; i < (int)this->_input.length(); i++)
	{
		if ((this->_input[i] < '0' || this->_input[i] > '9') && (this->_input[i] != '.' && this->_input[i] != 'f'))
			return (-1);
	}
	return (0);
}

int ScalarConverter::isChar()
{
	if (this->_input.length() > 1)
		return (-1);
	return (0);
}


void	ScalarConverter::toInt()
{
	int types[3] = {ft_char, ft_float, ft_double};
	int values[3] = {(int)this->_c, (int)this->_f, (int)this->_d};
	if (this->_type == ft_error)
	{
		this->_intFlag = 1;
		return ;
	}
	for (int i = 0; i < 3; i++)
	{
		if (this->_type == types[i])
		{
			this->_i = values[i];
			this->_intFlag = 0;
			return ;
		}
	}
}

void	ScalarConverter::toDouble(void)
{
	int types[3] = {ft_char, ft_int, ft_float};
	double values[3] = {(double)this->_c, (double)this->_i, (double)this->_f};
	if (this->_type == ft_error)
	{
		this->_doubleFlag = 1;
		return ;
	}
	for (int i = 0; i < 3; i++)
	{
		if (this->_type == types[i])
		{
			this->_d = values[i];
			this->_doubleFlag = 0;
			return ;
		}
	}
}

void	ScalarConverter::toFloat()
{
	int types[3] = {ft_char, ft_int, ft_double};
	float values[3] = {(float)this->_c, (float)this->_i, (float)this->_d};
	if (this->_type == ft_error)
	{
		this->_floatFlag = 1;
		return ;
	}
	for (int i = 0; i < 3; i++)
	{
		if (this->_type == types[i])
		{
			this->_f = values[i];
			this->_floatFlag = 0;
			return ;
		}
	}
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
}

//getters

std::string ScalarConverter::getInput(void)
{
	return (this->_input);
}

int ScalarConverter::getInt(void)
{
	return (this->_i);
}

char ScalarConverter::getChar(void)
{
	return (this->_c);
}

float ScalarConverter::getFloat(void)
{
	return (this->_f);
}

double ScalarConverter::getDouble(void)
{
	return (this->_d);
}

int ScalarConverter::getType(void)
{
	return (this->_type);
}

int ScalarConverter::getIntFlag(void)
{
    return (this->_intFlag);
}
int ScalarConverter::getCharFlag(void)
{
	return (this->_charFlag);
}

int ScalarConverter::getDoubleFlag(void)
{
	return (this->_doubleFlag);
}

int ScalarConverter::getFloatFlag(void)
{
	return (this->_floatFlag);
}



int	count_decimals(std::string value)
{
	int	count = 0;

	for (int i = 0; i < (int)value.length(); i++)
	{
		if (value[i] == '.')
			count += 1;
		else if (count && value[i] != 'f')
			count += 1;
	}
	if (count > 1)
		count -= 1;
	return (count);
}

std::ostream &operator<<(std::ostream &str, ScalarConverter &converter)
{
	std::string char_str = "";
	std::string int_str = "";
	std::string float_str = "";
	std::string double_str = "";


	int count = 1;
	if (converter.getType() == ft_float || converter.getType() == ft_double)
		count = count_decimals(converter.getInput());

	if (converter.getCharFlag() == 1)
		char_str = "impossible" ;
	else if (converter.getCharFlag() == 2)
		char_str = "Non displayable";
	if (converter.getIntFlag() == 1)
		int_str = "impossible";
	if (converter.getFloatFlag() == 1)
		float_str = "nanf";
	if (converter.getDoubleFlag() == 1)
		double_str = "nan";

	if (char_str == "")
		str << "char : '" << converter.getChar() << "'" << std::endl;
	else
		str << "char : " << char_str << std::endl;

	if (int_str == "")
		str << "int : " << converter.getInt() << std::endl;
	else
		str << "int : " << int_str << std::endl;

	if (float_str == "")
		str << std::fixed << std::setprecision(count) << "float : " << converter.getFloat() << "f" << std::endl;
	else
		str << "float : " << float_str << std::endl;

	if (double_str == "")
		str << std::fixed << std::setprecision(count) << "double : " << converter.getDouble();
	else
		str << "double : " << double_str;

	return (str);
}
