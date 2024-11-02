/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isType.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:25:16 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/02 15:28:44 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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