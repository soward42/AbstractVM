/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
	#define MEMORY_HPP_

#include <vector>
#include <array>
#include "IOperand.hpp"

class Memory {
public:
	Memory();
	~Memory();
	IOperand *popHeadStack();
	const std::vector<IOperand*> &getStack();
	void clearStack();
	void pushStack(IOperand*);
	void setRegitster(IOperand*, size_t);
	IOperand *getRegitster(size_t pos);
	size_t getStackSize() const;
private:
	std::vector<IOperand*>		_stack;
	std::array<IOperand*, 16>	_r;
};

#endif /* !MEMORY_HPP_ */
