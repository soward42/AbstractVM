/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
	#define EXCEPTION_HPP_

#include <string>
#include <iostream>
#include <sstream>

class AbstractException : public std::exception {
	public:
		AbstractException();
		AbstractException(const std::string &);
		AbstractException(const std::string &, const std::string &);
		~AbstractException();
		const char *what() const throw();
	private:
		void makeMessage(const std::string &, const std::string&);
		std::string _errorMsg;
};

#endif /* !EXCEPTION_HPP_ */
