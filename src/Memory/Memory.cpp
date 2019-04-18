/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Memory
*/

#include "Memory.hpp"
#include "Factory.hpp"

Memory::Memory()
{
	_r.fill(nullptr);
}

Memory::~Memory()
{
}

void Memory::setRegitster(IOperand *value, size_t pos)
{
	_r[pos] = value;
}

IOperand *Memory::getRegitster(size_t pos)
{
	return _r[pos];
}

void Memory::pushStack(IOperand *value)
{
	_stack.push_back(value);
}

const std::vector<IOperand*> &Memory::getStack()
{
	return _stack;
}

void Memory::clearStack()
{
	for (auto it = _stack.begin(); it != _stack.end(); it++)
		delete *it;
	_stack.clear();
}

IOperand *Memory::popHeadStack()
{
	IOperand	*tmp = Factory::createOperand((*(_stack.end() - 1))->getType(), (*(_stack.end() - 1))->toString());

	_stack.pop_back();
	return tmp;
}

size_t Memory::getStackSize() const
{
	return _stack.size();
}