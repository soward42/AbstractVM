/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <regex>
#include <string>
#include <iostream>
#include <map>
#include "IOperand.hpp"

class Parser {
public:
	Parser();
	~Parser() = default;
	std::string	getRegexMatchGroup(const std::string &, std::regex,size_t);
	const std::string &getFunctionName() const;
	const std::string &getValue() const;
	eOperandType getType() const;
	void parseInput(std::string&);
	void defineTypeFromValueType();
	void clearVariables();
private:
	bool	isInteger();
	bool	isFloat();
	void	checkInt8();
	void	checkInt16();
	void	checkInt32();
	void	checkFloat();
	void	checkDouble();
	void	checkBigDecimal();
	static const std::map<std::string, std::regex>	_regexList;
	std::string	_functionName;
	std::string	_valueType;
	std::string	_value;
	eOperandType	_type;
};

#endif /* !PARSER_HPP_ */
