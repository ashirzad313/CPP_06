/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:33:49 by ashirzad          #+#    #+#             */
/*   Updated: 2024/11/05 11:07:15 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	int *p = new int(42);
	// double *b = new double(2.5);

	char *c = reinterpret_cast<char*>(p);

	std::cout << c << std::endl;
}
