/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Parser
*/

#include "Parser.hpp"

const	std::map<std::string, std::regex>	Parser::_regexList({
	{"push", std::regex("[ \t]*push[ \t]+(int8|int16|int32|float|double|bigdecimal)\\(([-]?[0-9]+|[-]?[0-9]+.?[0-9]+)\\)[ \t]*")},
	{"assert", std::regex("[ \t]*assert[ \t]+(int8|int16|int32|float|double|bigdecimal)\\(([-]?[0-9]+|[-]?[0-9]+.?[0-9]+)\\)[ \t]*")},
	{"load", std::regex("[ \t]*load[ \t]+(int8|int16|int32|float|double|bigdecimal)\\(([-]?[0-9]+|[-]?[0-9]+.?[0-9]+)\\)[ \t]*")},
	{"store", std::regex("[ \t]*store[ \t]+(int8|int16|int32|float|double|bigdecimal)\\(([-]?[0-9]+|[-]?[0-9]+.?[0-9]+)\\)[ \t]*")},
	{"pop", std::regex("[ \t]*pop[ \t]*")},
	{"dump", std::regex("[ \t]*dump[ \t]*")},
	{"clear", std::regex("[ \t]*clear[ \t]*")},
	{"dup", std::regex("[ \t]*dup[ \t]*")},
	{"add", std::regex("[ \t]*add[ \t]*")},
	{"sub", std::regex("[ \t]*sub[ \t]*")},
	{"mul", std::regex("[ \t]*mul[ \t]*")},
	{"div", std::regex("[ \t]*div[ \t]*")},
	{"mod", std::regex("[ \t]*mod[ \t]*")},
	{"swap", std::regex("[ \t]*swap[ \t]*")},
	{"print", std::regex("[ \t]*print[ \t]*")},
	{"exit", std::regex("[ \t]*exit[ \t]*")},
	{"sqrt", std::regex("[ \t]*sqrt[ \t]*")}
});

Parser::Parser() : _functionName("")
{
}

const std::string &Parser::getFunctionName() const
{
	return _functionName;
}

const std::string &Parser::getValue() const
{
	return _value;
}

eOperandType Parser::getType() const
{
	return _type;
}

void	Parser::clearVariables()
{
	_functionName = "";
	_valueType = "";
	_value = "";
}

std::string	Parser::getRegexMatchGroup(const std::string &toTest, std::regex rgx, size_t nb)
{
	std::smatch matches;

	if(std::regex_search(toTest, matches, rgx)) {
		if (nb >= matches.size())
			return "";
		return matches[nb].str();
	}
	return "";
}

void	Parser::parseInput(std::string &input)
{
	if (input.empty())
		throw AbstractException("parser", "empty line in input");
	if (input.find(';') == 0)
		return;
	else if (input.find(';') != std::string::npos && input.find(';') > 0){
		auto it = input.begin() + input.find(';');
		input.erase(it, input.end());
	}
	for (const auto &it : _regexList) {
		if (std::regex_match(input, it.second)){
			_functionName = it.first;
			_valueType = getRegexMatchGroup(input, it.second, 1);
			_value = getRegexMatchGroup(input, it.second, 2);
			if (!_valueType.empty())
				defineTypeFromValueType();
			return;
		}
	}
	throw AbstractException("parser", "Invalid command");
}

void	Parser::defineTypeFromValueType()
{
	if ("int8" == _valueType)
		checkInt8();
	if ("int16" == _valueType)
		checkInt16();
	if ("int32" == _valueType)
		checkInt32();
	if ("float"  == _valueType)
		checkFloat();
	if ("double"  == _valueType)
		checkDouble();
	if ("bigdecimal" == _valueType)
		checkBigDecimal();
}

bool	Parser::isInteger()
{
	return (std::regex_match(_value, std::regex("[-]?[0-9]+")));
}

bool	Parser::isFloat()
{
	return (std::regex_match(_value, std::regex("[-]?[0-9]+[.]?[0-9]+")));
}

void	Parser::checkInt8()
{
	if (!isInteger())
		throw AbstractException("int8", "Invalid value");
	_type = INT8;
}

void	Parser::checkInt16()
{
	if (!isInteger())
		throw AbstractException("int16", "Invalid value");
	_type = INT16;
}

void	Parser::checkInt32()
{
	if (!isInteger())
		throw AbstractException("int32", "Invalid value");
	_type = INT32;
}

void	Parser::checkFloat()
{	
	if (!isFloat())
		throw AbstractException("float", "Invalid value");
	_type = FLOAT;
}

void	Parser::checkDouble()
{
	if (!isFloat())
		throw AbstractException("double", "Invalid value");
	_type = DOUBLE;
}

void	Parser::checkBigDecimal()
{
	if (!isFloat())
		AbstractException("big decimal", "Invalid value");
	_type = BIGDECIMAL;
}