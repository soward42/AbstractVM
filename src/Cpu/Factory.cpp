/*
** EPITECH PROJECT, 2021
** Factory.cpp
** File description:
** SYN_abstractVM_2017
*/

#include "Factory.hpp"
#include <iostream>

std::map<eOperandType, IOperand *(Factory::*)(const std::string &)> Factory::createMap()
{
	std::map<eOperandType, IOperand *(Factory::*)(const std::string &)> map;

	map[INT8] = &Factory::createInt8;
	map[INT16] = &Factory::createInt16;
	map[INT32] = &Factory::createInt32;
	map[FLOAT] = &Factory::createFloat;
	map[DOUBLE] = &Factory::createDouble;
	map[BIGDECIMAL] = &Factory::createBigDecimal;
	return map;
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
	static std::map<eOperandType, IOperand *(Factory::*)(const std::string &)> map = Factory::createMap();
	IOperand *(Factory::*ptr)(const std::string &) = map[type];
	Factory *p = nullptr;

	return ((p->*ptr)(value));
}

IOperand *Factory::createInt8(const std::string &value)
{
	return new Operand<int8_t>(INT8, value);
}

IOperand *Factory::createInt16(const std::string &value)
{
	return new Operand<int16_t>(INT16, value);
}

IOperand *Factory::createInt32(const std::string &value)
{
	return new Operand<int32_t>(INT32, value);
}

IOperand *Factory::createFloat(const std::string &value)
{
	return new Operand<float>(FLOAT, value);
}

IOperand *Factory::createDouble(const std::string &value)
{
	return new Operand<double>(DOUBLE, value);
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
	return new Operand<long double>(BIGDECIMAL, value);
}