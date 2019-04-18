/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** UT_parser
*/

#include <criterion/criterion.h>
#include "Parser.hpp"


Test(Parser, getRegexMatchGroup)
{
	std::string	input("add");
	std::regex	rgx("add");
	Parser		parser;

	cr_assert_eq(parser.getRegexMatchGroup(input, rgx, 0), "add");
	input = "push int9(42)";
	rgx = "push[ ](int8|int16|int32|float|double|big decimal)\\(([-]?[0-9]+|[-]?[0-9]+.?[0-9]+)\\)";
	cr_assert_eq(parser.getRegexMatchGroup(input, rgx, 1), "");
}

Test(Parser, parseInput)
{
	Parser parser;
	std::string input("");

	cr_assert_any_throw(parser.parseInput(input));
	input = "toto";
	cr_assert_any_throw(parser.parseInput(input));
	input = "push int8(42);toto";
	cr_assert_none_throw(parser.parseInput(input));
	cr_assert_eq(parser.getType(), INT8);
	cr_assert_eq(parser.getValue(), "42");
	cr_assert_eq(parser.getFunctionName(), "push");
}
