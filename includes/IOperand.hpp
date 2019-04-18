/*
** EPITECH PROJECT, 2018
** abstractTMP
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
	#define IOPERAND_HPP_

#include <string>
#include "AbstractException.hpp"

enum	eOperandType {
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE,
	BIGDECIMAL,
};

class IOperand {
public:
	virtual std::string toString() const = 0;
	virtual eOperandType getType() const = 0;

	virtual IOperand *operator+(const IOperand &rhs) const = 0;
	virtual IOperand *operator-(const IOperand &rhs) const = 0;
	virtual IOperand *operator*(const IOperand &rhs) const = 0;
	virtual IOperand *operator/(const IOperand &rhs) const = 0;
	virtual IOperand *operator%(const IOperand &rhs) const = 0;

	virtual ~IOperand() {}
protected:
private:
};

#endif /* !IOPERAND_HPP_ */
