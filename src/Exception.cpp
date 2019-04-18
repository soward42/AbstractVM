/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** AbstractException
*/

#include "AbstractException.hpp"

AbstractException::AbstractException()
{
	makeMessage("", "An error occured");
}

AbstractException::AbstractException(const std::string &where)
{
	makeMessage(where, "An error occured");
}

AbstractException::AbstractException(const std::string &where, const std::string &what)
{
	makeMessage(where, what);
}


AbstractException::~AbstractException()
{
}

const char *AbstractException::what() const throw()
{
	return _errorMsg.c_str();
}

void AbstractException::makeMessage(const std::string &where,
const std::string &what)
{
	std::stringstream	output;

	output << where << ": " << what << std::endl;
	_errorMsg = output.str();
}
