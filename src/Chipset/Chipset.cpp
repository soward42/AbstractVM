/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Chipset
*/

#include "Chipset.hpp"

Chipset::Chipset(std::string &input, IO &io) : _input(input), _io(io)
{
}

void	Chipset::verifExit()
{
	if (!_cpu.getExit())
		throw  AbstractException("file", "No exit found");
}

void	Chipset::setInput(std::string &input)
{
	_input = input;
}

void	Chipset::translateAndExecute()
{
	_parser.parseInput(_input);
	if (!_parser.getFunctionName().empty()){
		_cpu.execCmd(_parser.getFunctionName(), _parser.getType(),
		_parser.getValue(), _memory, _io);
		_parser.clearVariables();
	}
}