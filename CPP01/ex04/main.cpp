/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:11:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:44 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>
#include <iostream>
#include <cstdlib>

void printUsage()
{
    std::cout << "./replace <filename> <str to replace> <str to replace with>";
    std::cout << std::endl;
    throw std::invalid_argument("Invalid arguments");
}

std::string readFile(std::string name)
{
    std::ifstream ifs;
    std::string buff;
    std::string content;

    ifs.open(name.c_str());
    if (ifs.fail())
        throw std::runtime_error("Fail to open the infile");
    while (std::getline(ifs, buff))
        content.append(buff + '\n');
    ifs.close();
    return (content);
}

std::string searchReplace(std::string& input, std::string& to_replace, std::string& replace_with)
{
    std::string result;
    size_t pos = 0;
    size_t start = 0;
    if (to_replace.empty())
        return input;
    while ((pos = input.find(to_replace, start)) != std::string::npos)
    {
        result += input.substr(start, pos - start);
        result += replace_with; 
		start = pos + to_replace.length();
	}
    result += input.substr(start);
	return result;
}

void writeFile(std::string name, std::string& output)
{
    std::ofstream ofs;
	std::string new_file = name + ".replace";

    ofs.open(new_file.c_str());
    if (ofs.fail())
        throw std::runtime_error("Fail to open the outfile");
    ofs << output;
    ofs.close();
}

int main(int argc, char** argv)
{
    try
    {
        if (argc < 4)
            printUsage();
        std::string to_replace = argv[2];
        std::string replace_with = argv[3];
        std::string input = readFile(argv[1]);
        std::string output = searchReplace(input, to_replace, replace_with);
        writeFile(argv[1], output);
        return (EXIT_SUCCESS);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
}
