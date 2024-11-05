/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:50:55 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/05 13:06:16 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>
#include <iomanip>
#include <ctime>

class Base
{
	public :
		Base(void);
		virtual ~Base(void);

		//methods
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);


};

#endif // __BASE_HPP__ //
