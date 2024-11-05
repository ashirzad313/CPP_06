/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:51:53 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/05 13:10:38 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::Base(void) {}

Base::~Base(void) {}

//methods

Base	*Base::generate(void)
{
	srand(time(0));
	Base *list[3] = {new A(), new B(), new C()};

	int choice = rand() % 3;
	for (int i = 0; i < 3; i++)
	{
		if (i != choice)
			delete list[i];
	}
	return (list[choice]);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << "Someother Type" << std::endl;
}

void Base::identify(Base& p)
{
	try {
		Base &base = dynamic_cast<A&>(p);
		(void)base;
		std::cout << "Type A" << std::endl;
	}
	catch (std::exception &e){}
	try {
		Base &base = dynamic_cast<B&>(p);
		(void)base;
		std::cout << "Type B" << std::endl;
	}
	catch (std::exception &e){}
	try {
		Base &base = dynamic_cast<C&>(p);
		(void)base;
		std::cout << "Type C" << std::endl;
	}
	catch (std::exception &e){}
}

