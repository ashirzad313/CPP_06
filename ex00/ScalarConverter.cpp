/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:26:40 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/01 14:38:36 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Orthodox Canonical Form

ScalarConverter::ScalarConverter(void): _value("default"), _c(0), _i(-1), _f(-1), _d(-1) {}

ScalarConverter::ScalarConverter(ScalarConverter &copy): _value(copy._value), _c(copy._c), _i(copy._i), _f(copy._f), _d(copy._d)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	this->_value = other._value;
	this->_c = other._c;
	this->_i = other._i;
	this->_f = other._f;
	this->_d = other._d;
	return (*this);
}

ScalarConverter::~ScalarConverter(void){}

// methods


int	int_type(std::string value)
{
	for (int i = 0; i < (int)value.length(); i++)
	{
		if (value[i] < '0' || value[i] > '9')
			return (-1);
	}
	return (0);
}

int	double_type(std::string value)
{
	int dot_count = std::count(value.begin(), value.end(), '.');
	if (dot_count != 1)
		return (-1);
	for (int i = 0; i < (int)value.length(); i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.')
			return (-1);
	}
	return (0);
}

int	float_type(std::string value)
{
	int dot_count = std::count(value.begin(), value.end(), '.');
	int	f_count = std::count(value.begin(), value.end(), 'f');
	if (dot_count != 1 || f_count > 1)
		return (-1);
	for (int i = 0; i < (int)value.length(); i++)
	{
		if ((value[i] < '0' || value[i] > '9') && (value[i] != '.' && value[i] != 'f'))
			return (-1);
	}
	return (0);
}

int char_type(std::string value)
{
	if (value.length() > 1)
		return (-1);
	return (0);
}

std::string ScalarConverter::detect_type(std::string value)
{
	std::string type = "";
	if (int_type(value) != -1)
		type = "int";
	else if (double_type(value) != -1)
		type = "double";
	else if (float_type(value) != -1)
		type = "float";
	else if (char_type(value) != -1)
		type = "char";
	return (type);
}

void	ScalarConverter::convert(std::string value)
{
	std::string input = ScalarConverter::detect_type(value);
	if (input == "")
		throw InvalidType();
	std::cout << input << std::endl;
}

// object errors

 const char *ScalarConverter::InvalidType::what(void) const throw()
{
	return ("Invalid Type detected");
}
