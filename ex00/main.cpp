/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:28:38 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/02 15:05:51 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int args, char **argv)
{
	if (args != 2)
	{
		std::cout << "Invalid args" << std::endl;
		return (-1);
	}
	try {
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}
