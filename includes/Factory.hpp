/*
** EPITECH PROJECT, 2021
** Factory.hpp
** File description:
** SYN_abstractVM_2017
*/
#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IOperand.hpp"
#include "Operand.hpp"
#include <map>

class Factory
{
public:
	Factory() = default;
	~Factory() = default;
	static IOperand *createOperand(eOperandType type, const std::string &value);
	static std::map<eOperandType, IOperand *(Factory::*)(const std::string &)> createMap();
private:
	IOperand *createInt8(const std::string &value);
	IOperand *createInt16(const std::string &value);
	IOperand *createInt32(const std::string &value);
	IOperand *createFloat(const std::string &value);
	IOperand *createDouble(const std::string &value);
	IOperand *createBigDecimal(const std::string &value);
};

#endif /* !FACTORY_HPP */
