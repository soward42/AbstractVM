/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Chipset
*/

#ifndef CHIPSET_HPP_
	#define CHIPSET_HPP_

#include "Parser.hpp"
#include "Cpu.hpp"
#include "IO.hpp"

class Chipset {
public:
	Chipset(std::string &input, IO &io);
	~Chipset() = default;
	void	verifExit();
	void	setInput(std::string &);
	void	translateAndExecute();
protected:
private:
	std::string &_input;
	IO	&_io;
	Memory	_memory;
	Cpu	_cpu;
	Parser	_parser;
};

#endif /* !CHIPSET_HPP_ */
