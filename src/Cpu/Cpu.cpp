/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Cpu.cpp
*/
#include "Cpu.hpp"

Cpu::Cpu()
	: _exit(false), _map(createMap())
{
}

std::map<std::string, void(Cpu::*)(eOperandType, const std::string &, Memory &)> Cpu::createMap()
{
	std::map<std::string, void (Cpu::*)(eOperandType, const std::string &, Memory &)> map;

	map["push"] = &Cpu::push;
	map["pop"] = &Cpu::pop;
	map["clear"] = &Cpu::clear;
	map["dup"] = &Cpu::dup;
	map["swap"] = &Cpu::swap;
	map["assert"] = &Cpu::assert;
	map["add"] = &Cpu::add;
	map["sub"] = &Cpu::sub;
	map["mul"] = &Cpu::mul;
	map["div"] = &Cpu::div;
	map["mod"] = &Cpu::mod;
	map["exit"] = &Cpu::exitCmd;
	map["load"] = &Cpu::load;
	map["store"] = &Cpu::store;
	map["sqrt"] = &Cpu::sqrt;
	return map;
}

void Cpu::execCmd(const std::string &cmd, eOperandType type, const std::string &value, Memory &memory, IO &io)
{
	void (Cpu::*ptr)(eOperandType, const std::string &, Memory &);

	if (cmd == "print")
		io.print(this->print(memory));
	else if (cmd == "dump")
		io.dump(this->dump(memory));
	else {
		ptr = _map[cmd];
		((this->*ptr)(type, value, memory));
	}
}

void Cpu::push(eOperandType type, const std::string &value, Memory &memory)
{
	IOperand	*toPush = Factory::createOperand(type, value);

	memory.pushStack(toPush);
}

void Cpu::pop(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand *toPop;

	checkMemorySize(1, memory, "pop", "Insufficient element in stack");
	toPop = memory.popHeadStack();
	delete toPop;
}

void Cpu::clear(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	memory.clearStack();
}

void Cpu::dup(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*origin;
	IOperand	*dup;

	checkMemorySize(1, memory, "dup", "Insufficient element in stack");
	origin = memory.popHeadStack();
	dup = Factory::createOperand(origin->getType(), origin->toString());
	memory.pushStack(origin);
	memory.pushStack(dup);
}

void Cpu::swap(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*first;
	IOperand	*second;

	checkMemorySize(2, memory, "swap", "Insufficient element in stack");
	first = memory.popHeadStack();
	second = memory.popHeadStack();
	memory.pushStack(first);
	memory.pushStack(second);
}

void Cpu::assert(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*toAssert;

	checkMemorySize(1, memory, "assert", "Insufficient element in stack");
	toAssert = memory.popHeadStack();
	if (toAssert->toString() != value)
		throw AbstractException("assert", "the expression is false");
	memory.pushStack(toAssert);
}

void Cpu::add(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	checkMemorySize(2, memory, "add", "Insufficient element in stack");
	op1 = memory.popHeadStack();
	op2 = memory.popHeadStack();
	res = *op1 + *op2;
	delete op1;
	delete op2;
	memory.pushStack(res);
}

void Cpu::sub(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	checkMemorySize(2, memory, "sub", "Insufficient element in stack");
	op2 = memory.popHeadStack();
	op1 = memory.popHeadStack();
	res = *op1 - *op2;
	delete op1;
	delete op2;
	memory.pushStack(res);
}

void Cpu::mul(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	checkMemorySize(2, memory, "mul", "Insufficient element in stack");
	op2 = memory.popHeadStack();
	op1 = memory.popHeadStack();
	res = *op1 * *op2;
	delete op1;
	delete op2;
	memory.pushStack(res);
}

void Cpu::div(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	checkMemorySize(2, memory, "div", "Insufficient element in stack");
	op2 = memory.popHeadStack();
	op1 = memory.popHeadStack();
	res = *op1 / *op2;
	delete op1;
	delete op2;
	memory.pushStack(res);
}

void Cpu::mod(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	checkMemorySize(2, memory, "mod", "Insufficient element in stack");
	op2 = memory.popHeadStack();
	op1 = memory.popHeadStack();
	res = *op1 % *op2;
	delete op1;
	delete op2;
	memory.pushStack(res);
}

void Cpu::exitCmd(UNUSED eOperandType type, UNUSED const std::string &value, UNUSED Memory &memory)
{
	_exit = true;
}

bool Cpu::getExit() const
{
	return Cpu::_exit;
}

IOperand	*Cpu::print(Memory &memory)
{
	IOperand	*tmp;

	checkMemorySize(1, memory, "print", "Insufficient element in stack");
	tmp = memory.popHeadStack();
	if (tmp->getType() != INT8)
		throw AbstractException("print", "wrong type of value to print");
	memory.pushStack(Factory::createOperand(INT8, tmp->toString()));
	return (tmp);
}

const std::vector<IOperand *> &Cpu::dump(Memory &memory)
{
	return memory.getStack();
}

void Cpu::load(eOperandType type, const std::string &value, Memory &memory)
{
	IOperand	*tmp;
	size_t		reg_pos = std::stoll(value);

	if (type >= FLOAT)
		throw AbstractException("load", "invalid type value.");
	if (reg_pos > 15)
		throw AbstractException("load", "invalid value. The value must be 0-15.");
	tmp = memory.getRegitster(reg_pos);
	if (tmp == nullptr)
		throw AbstractException("load", "empty register targeted");
	memory.pushStack(tmp);
}

void Cpu::store(UNUSED eOperandType type, UNUSED const std::string &value, UNUSED Memory &memory)
{
	IOperand	*tmp;
	size_t		reg_pos = std::stoll(value);

	if (type >= FLOAT)
		throw AbstractException("store", "invalid type value.");
	if (reg_pos > 15)
		throw AbstractException("store", "invalid value. The value must be 0-15.");
	if (memory.getStackSize() == 0)
		throw AbstractException("store", "Cannot store anything from empty stack.");
	tmp = memory.popHeadStack();
	memory.setRegitster(tmp, reg_pos);
}

void Cpu::sqrt(UNUSED eOperandType type, UNUSED const std::string &value, Memory &memory)
{
	IOperand *tmp;

	checkMemorySize(1, memory, "sqrt", "cannot square-root if the stack is empty");
	tmp = memory.popHeadStack();
	tmp = Operand<float>::squareRoot(tmp);
	memory.pushStack(tmp);
}

void		Cpu::checkMemorySize(size_t size, Memory &memory, std::string where, std::string what)
{
	if (memory.getStackSize() < size)
		throw AbstractException(where, what);
}