/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:34:06 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/02 16:43:17 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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