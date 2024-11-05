/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:21:28 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/05 11:47:14 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <iostream>
#include <iomanip>

class Data
{
	private :
		std::string _name;
		int			_age;
	public :
		Data(void);
		Data(std::string name, int age);
		Data(Data &copy);
		Data &operator=(Data &other);
		~Data(void);

		//getters
		std::string getName(void);
		int	getAge(void);

		//setters
		void	setName(std::string name);
		void	setAge(int age);
};

std::ostream &operator<<(std::ostream &str, Data &data);

#endif // __Data_HPP__ //
