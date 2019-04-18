/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** IO.hpp
*/

#ifndef IO_HPP_
	#define IO_HPP_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include "IOperand.hpp"

class IO
{
public:
	explicit IO();
	int		readStandard();
	int		readFile(const char *);
	size_t 		getSize() const;
	std::string	&getNextLine();
	void		print(IOperand *);
	void		dump(std::vector<IOperand *>);
private:
	std::vector<std::string>	_lines;
	size_t 				_pos;
};

#endif /* !IO_HPP_ */
