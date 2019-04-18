/*
** EPITECH PROJECT, 2021
** Operand.cpp
** File description:
** SYN_abstractVM_2017
*/

#include "Operand.hpp"

template<typename T>
Operand<T>::Operand(eOperandType type, const std::string &value)
	: _type(type), _str(value)
{
	long double tmp = std::stold(value);

	if (tmp > std::numeric_limits<T>::max() || tmp < std::numeric_limits<T>::lowest())
		throw AbstractException("operand", "underflow or overflow");
	this->_value = static_cast<T>(std::stold(value));
}

template<typename T>
std::string Operand<T>::toString() const
{
	return this->_str;
}

template<typename T>
eOperandType Operand<T>::getType() const
{
	return this->_type;
}

template<typename T>
IOperand *Operand<T>::squareRoot(IOperand* value)
{
	long double res = std::stold(value->toString());
	auto nType = value->getType();

	if (res < 0)
		throw AbstractException("sqrt", "cannot square-root a negative number");
	res = std::sqrt(res);
	return Factory::createOperand(nType, setPrecision(nType, res));
}

template<typename T>
IOperand* Operand<T>::operator%(const IOperand &rhs) const
{
	long double op1 = std::stold(this->toString());
	long double op2 = std::stold(rhs.toString());
	eOperandType newType = this->getType();

	if (newType < rhs.getType())
		newType = rhs.getType();
	if (op2 == 0)
		throw AbstractException("mod", "modulo by zero");
	op1 = std::fmod(op1, op2);
	return Factory::createOperand(newType, this->setPrecision(newType, op1));
}

template<typename T>
IOperand* Operand<T>::operator*(const IOperand &rhs) const
{
	long double op1 = std::stold(this->toString());
	long double op2 = std::stold(rhs.toString());
	eOperandType newType = this->getType();

	if (newType < rhs.getType())
		newType = rhs.getType();
	op1 *= op2;
	return Factory::createOperand(newType, this->setPrecision(newType, op1));
}

template<typename T>
IOperand *Operand<T>::operator+(const IOperand &rhs) const
{
	long double op1 = std::stold(this->toString());
	long double op2 = std::stold(rhs.toString());
	eOperandType newType = this->getType();

	if (newType < rhs.getType())
		newType = rhs.getType();
	if (op2 > 0 && std::numeric_limits<double long>::max() - op2 < op1)
		throw AbstractException("operand", "overflowing value");
	if (op2 < 0 && std::numeric_limits<double long>::lowest() - op2 > op1)
		throw AbstractException("operand", "underflowing value");
	op1 += op2;
	return Factory::createOperand(newType, this->setPrecision(newType, op1));
}

template<typename T>
IOperand *Operand<T>::operator-(const IOperand &rhs) const
{
	long double op1 = std::stold(this->toString());
	long double op2 = std::stold(rhs.toString());
	eOperandType newType = this->getType();

	if (newType < rhs.getType())
		newType = rhs.getType();
	op1 -= op2;
	return Factory::createOperand(newType, this->setPrecision(newType, op1));
}

template<typename T>
IOperand* Operand<T>::operator/(const IOperand &rhs) const
{
	long double op1 = std::stold(this->toString());
	long double op2 = std::stold(rhs.toString());
	eOperandType newType = this->getType();

	if (newType < rhs.getType())
		newType = rhs.getType();
	if (op2 == 0)
		throw AbstractException("div", "division by zero");
	op1 /= op2;
	return Factory::createOperand(newType, this->setPrecision(newType, op1));
}

template<typename T>
const std::string Operand<T>::setPrecision(eOperandType type, long double value)
{
	std::string str = std::to_string(value);
	size_t i;

	if (type < FLOAT)
		str.erase((str.begin() + str.find('.')), str.end());
	else {
		for (i = str.size() - 1; str[i] == '0'; i--);
		if (str[i] != '.')
  			str.erase((str.begin() + (i + 1)), str.end());
		else
			str.erase((str.begin() + str.find('.')), str.end());
	}
	return str;
}