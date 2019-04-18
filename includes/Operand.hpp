/*
** EPITECH PROJECT, 2021
** Operand.hpp
** File description:
** SYN_abstractVM_2017
*/
#ifndef OPERAND_HPP_
	#define OPERAND_HPP_

#include "IOperand.hpp"
#include "Factory.hpp"
#include <sstream>
#include <limits>
#include <iomanip>
#include <iostream>
#include <cmath>

template<typename T>
class Operand : public IOperand
{
public:
	Operand(eOperandType type, const std::string &value);
	std::string toString() const override;
	eOperandType getType() const override;
	static IOperand *squareRoot(IOperand*);
	static const std::string setPrecision(eOperandType type, long double nb);
	IOperand *operator+(const IOperand &rhs) const override;
	IOperand *operator-(const IOperand &rhs) const override;
	IOperand *operator*(const IOperand &rhs) const override;
	IOperand *operator/(const IOperand &rhs) const override;
	IOperand *operator%(const IOperand &rhs) const override;
private:
	eOperandType _type;
	std::string _str;
	T _value;
};

template class Operand<int8_t>;
template class Operand<int16_t >;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
template class Operand<long double>;

#endif /* !OPERAND_HPP */
