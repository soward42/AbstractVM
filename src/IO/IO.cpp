/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** IO.cpp
*/

#include "IO.hpp"

IO::IO()
	: _lines(0), _pos(0)
{
}

int IO::readFile(const char *filename)
{
	std::ifstream	file(filename);
	std::string	tmp;

	if (file.is_open() && file.peek() != std::ifstream::traits_type::eof()){
		while (getline(file, tmp))
			IO::_lines.push_back(tmp);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

int IO::readStandard()
{
	std::string	tmp;

	while (tmp.find(";;") == std::string::npos) {
		getline(std::cin, tmp);
		if (tmp.empty())
			continue;
		if (tmp.find(";;") == std::string::npos)
			IO::_lines.push_back(tmp);
	}
	return EXIT_SUCCESS;
}

std::string	&IO::getNextLine()
{
	if (_pos == IO::_lines.size())
		return (std::string &)"";
	return (IO::_lines[IO::_pos++]);
}

size_t	IO::getSize() const
{
	return (IO::_lines.size());
}

void	IO::print(IOperand *toPrint)
{
	int c = std::stoi(toPrint->toString());

	std::cout << (char)c << std::endl;
	delete toPrint;
}

void	IO::dump(std::vector<IOperand *> toPrint)
{
	if (toPrint.end() == toPrint.begin())
		return;
	for (auto it = (toPrint.end() - 1); it >= toPrint.begin(); it--) {
		std::cout << (*it)->toString() << std::endl;
	}
}