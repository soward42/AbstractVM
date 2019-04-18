/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Cpu.hpp
*/

#ifndef CPU_HPP_
	#define CPU_HPP_

#include <cstdlib>
#include "Memory.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "IO.hpp"

#define UNUSED __attribute__((unused))

class Cpu
{
public:
	Cpu();
	~Cpu() = default;
	void execCmd(const std::string &, eOperandType, const std::string &, Memory &, IO &);
	bool getExit() const;
private:
	void push(eOperandType, const std::string &, Memory &);
	void pop(eOperandType, const std::string &, Memory &);
	void clear(eOperandType, const std::string &, Memory &);
	void dup(eOperandType, const std::string &, Memory &);
	void swap(eOperandType, const std::string &, Memory &);
	void assert(eOperandType, const std::string &, Memory &);
	void add(eOperandType, const std::string &, Memory &);
	void sub(eOperandType, const std::string &, Memory &);
	void div(eOperandType, const std::string &, Memory &);
	void mul(eOperandType, const std::string &, Memory &);
	void mod(eOperandType, const std::string &, Memory &);
	void exitCmd(eOperandType, const std::string &, Memory &);
	void load(eOperandType, const std::string &, Memory &);
	void store(eOperandType, const std::string &, Memory &);
	void sqrt(eOperandType, const std::string &, Memory &);
	void checkMemorySize(size_t, Memory &, std::string, std::string);
	IOperand *print(Memory &);
	const std::vector<IOperand *> &dump(Memory &);
	std::map<std::string, void(Cpu::*)(eOperandType, const std::string &, Memory &)> createMap();
private:
	bool _exit;
	std::map<std::string, void(Cpu::*)(eOperandType, const std::string &, Memory &)> _map;
};

#endif /* !CPU_HPP_ */
