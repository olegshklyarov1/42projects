/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 16:30:41 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/14 17:45:06 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


static std::string replace(const std::string& content, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
		return content;
	std::string result = "";
	size_t pos = 0;
	size_t found;
	
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	
	return result;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <string1> <string2>" << std::endl;
		return EXIT_FAILURE;
	}
	
	const std::string filename = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return EXIT_FAILURE;
	}
	
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: cannot open " << filename << std::endl;
		return EXIT_FAILURE;
	}
	
	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	inputFile.close();
	
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cout << "Error: Cannot create output file: " << filename << ".replace" << std::endl;
		return EXIT_FAILURE;
	}
	outputFile << replace(buffer.str(), s1, s2);
	outputFile.close();
	
	return EXIT_SUCCESS;
}