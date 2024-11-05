/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:21:04 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/05 11:49:17 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): _name("default"), _age(0){}

Data::Data(std::string name, int age): _name(name), _age(age) {}

Data::Data(Data &copy): _name(copy._name), _age(copy._age)
{
	*this = copy;
}

Data &Data::operator=(Data &other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_age = other._age;
	return (*this);
}

Data::~Data(void) {}

std::string Data::getName(void)
{
	return (this->_name);
}

int Data::getAge(void)
{
	return (this->_age);
}

void	Data::setName(std::string name)
{
	this->_name = name;
}

void	Data::setAge(int age)
{
	this->_age = age;
}

std::ostream &operator<<(std::ostream &str, Data &data)
{
	return (str << "Name : " << data.getName() << ", Age : " << data.getAge());
}
