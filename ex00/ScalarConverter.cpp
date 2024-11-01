/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:26:40 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/01 18:09:17 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Orthodox Canonical Form

ScalarConverter::ScalarConverter(void): _isError(0), _isInt(0), _isDouble(0), _isFloat(0),_isChar(0)  {}

ScalarConverter::ScalarConverter(ScalarConverter &copy): _isError(0), _isInt(0), _isDouble(0), _isFloat(0),_isChar(0)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	// assign vars
	return (*this);
}

ScalarConverter::~ScalarConverter(void){}

// methods

int	ScalarConverter::isInt(std::string value)
{
	for (int i = 0; i < (int)value.length(); i++)
	{
		if (value[i] < '0' || value[i] > '9')
			return (-1);
	}
	return (0);
}

int	ScalarConverter::isDouble(std::string value)
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

int	ScalarConverter::isFloat(std::string value)
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

int ScalarConverter::isChar(std::string value)
{
	if (value.length() > 1)
		return (-1);
	return (0);
}

void ScalarConverter::detect_type(std::string value)
{
	if (this->isInt(value) != -1)
	{
		this->_i = std::stoi(value);
		this->_isInt = 1;
	}
	else if (this->isDouble(value) != -1)
	{
		this->_d = std::stod(value);
		this->_isDouble = 1;
	}
	else if (this->isFloat(value) != -1)
	{
		this->_f = std::stof(value);
		this->_isFloat = 1;
	}
	else if (this->isChar(value) != -1)
	{
		this->_c = (char)value[0];
		this->_isChar = 1;
	}
	else
		this->_isError = 1;
}

// To Methods
void	ScalarConverter::toChar()
{
	int	n = 32;
	if (this->_isError)
		throw CharError();
	else if (this->_isChar == 1)
		n = (int)this->_c;
	else if (this->_isInt == 1)
		n = this->_i;
	else if (this->_isDouble == 1)
		n = (int)this->_d;
	else if (this->_isFloat == 1)
		n = (int)this->_f;
	if (n < 32 || n > 126)
		throw CharError();
	char	c = (char)n;
	std::cout << "char : '" << c << "'" << std::endl;
}

void	ScalarConverter::toInt()
{
	int n = 0;
	if (this->_isError)
		throw IntError();
	else if (this->_isInt == 1)
		n = (int)this->_i;
	else if (this->_isChar == 1)
		n = (int)this->_c;
	else if (this->_isDouble == 1)
		n = (int)this->_d;
	else if (this->_isFloat == 1)
		n = (int)this->_f;
	std::cout << "int : " << n << std::endl;
}

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

void	ScalarConverter::toDouble(std::string value)
{
	double n = 0;
	int		perc = 1;
	if (this->_isError)
		throw DoubleError();
	else if (this->_isInt == 1)
		n = (double)this->_i;
	else if (this->_isChar == 1)
		n = (double)this->_c;
	else if (this->_isDouble == 1)
		n = (double)this->_d;
	else if (this->_isFloat == 1)
		n = (double)this->_f;

	if (this->_isDouble == 1 || this->_isFloat == 1)
		perc = count_decimals(value);
	std::cout << std::fixed << std::setprecision(perc) << "double : " << n << std::endl;
}

void	ScalarConverter::toFloat(std::string value)
{
	float n = 0;
	int		perc = 1;
	if (this->_isError)
		throw FloatError();
	else if (this->_isInt == 1)
		n = (float)this->_i;
	else if (this->_isChar == 1)
		n = (float)this->_c;
	else if (this->_isDouble == 1)
		n = (float)this->_d;
	else if (this->_isFloat == 1)
		n = (float)this->_f;

	if (this->_isDouble == 1 || this->_isFloat == 1)
		perc = count_decimals(value);
	std::cout << std::fixed << std::setprecision(perc) << "float : " << n << "f" << std::endl;
}

void	ScalarConverter::convert(std::string value)
{
	ScalarConverter converter;
	converter.detect_type(value);
	try {
		converter.toChar();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		converter.toInt();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		converter.toFloat(value);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		converter.toDouble(value);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

// object errors

const char *ScalarConverter::CharError::what(void) const throw()
{
	return ("char : impossible");
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
