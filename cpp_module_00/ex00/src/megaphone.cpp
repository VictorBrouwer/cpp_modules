/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:50:37 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/09/26 16:07:05 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
			argv[i][j] = toupper(argv[i][j]);
		std::cout<<argv[i];
	}
	std::cout << std::endl;
	return (0);
}