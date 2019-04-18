/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** UT_cpu
*/

#include <criterion/criterion.h>
#include "Cpu.hpp"
#include "Memory.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "IO.hpp"
#include "Parser.hpp"

Test(Cpu, cmd_push)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res;

	cpu.execCmd("push", INT8, "0", memory, io);
	res = memory.popHeadStack();
	cr_assert_eq(res->getType(), INT8);
	cr_assert_eq(res->toString(), "0");
	delete res;
}

Test(Cpu, cmd_pop)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;

	cpu.execCmd("push", INT8, "0", memory, io);
	cpu.execCmd("pop", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 0);
	cr_assert_any_throw(cpu.execCmd("pop", INT8, "0", memory, io));
}


Test(Cpu, cmd_clear)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;

	cpu.execCmd("push", INT8, "0", memory, io);
	cpu.execCmd("clear", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 0);
}

Test(Cpu, cmd_dup)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res;

	cpu.execCmd("push", INT8, "0", memory, io);
	cpu.execCmd("dup", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 2);
	res = memory.popHeadStack();
	cr_assert_eq(res->getType(), INT8);
	cr_assert_eq(res->toString(), "0");
	delete res;
}

Test(Cpu, cmd_swap)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res1;
	IOperand *res2;

	cpu.execCmd("push", INT8, "0", memory, io);
	cpu.execCmd("push", INT16, "1", memory, io);
	cpu.execCmd("swap", INT8, "0", memory, io);
	res1 = memory.popHeadStack();
	res2 = memory.popHeadStack();
	cr_assert_eq(res1->getType(), INT8);
	cr_assert_eq(res1->toString(), "0");
	cr_assert_eq(res2->getType(), INT16);
	cr_assert_eq(res2->toString(), "1");
	delete res1;
	delete res2;
}

Test(Cpu, cmd_assert)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;

	cpu.execCmd("push", INT8, "0", memory, io);
	cr_assert_any_throw(cpu.execCmd("assert", INT8, "1", memory, io));
}

Test(Cpu, cmd_add)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res;

	cr_assert_any_throw(cpu.execCmd("add", INT8, "0", memory, io));
	cpu.execCmd("push", INT8, "1", memory, io);
	cpu.execCmd("push", INT8, "1", memory, io);
	cpu.execCmd("add", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 1);
	res = memory.popHeadStack();
	cr_assert_eq(res->getType(), INT8);
	cr_assert_eq(res->toString(), "2");
	delete res;
}

Test(Cpu, cmd_sub)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res;

	cr_assert_any_throw(cpu.execCmd("sub", INT8, "0", memory, io));
	cpu.execCmd("push", INT8, "1", memory, io);
	cpu.execCmd("push", INT8, "1", memory, io);
	cpu.execCmd("sub", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 1);
	res = memory.popHeadStack();
	cr_assert_eq(res->getType(), INT8);
	cr_assert_eq(res->toString(), "0");
	delete res;
}

Test(Cpu, cmd_mul)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res;

	cr_assert_any_throw(cpu.execCmd("mul", INT8, "0", memory, io));
	cpu.execCmd("push", INT8, "2", memory, io);
	cpu.execCmd("push", INT8, "2", memory, io);
	cpu.execCmd("mul", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 1);
	res = memory.popHeadStack();
	cr_assert_eq(res->getType(), INT8);
	cr_assert_eq(res->toString(), "4");
	delete res;
}

Test(Cpu, cmd_div)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res;

	cr_assert_any_throw(cpu.execCmd("div", INT8, "0", memory, io));
	cpu.execCmd("push", INT8, "4", memory, io);
	cpu.execCmd("push", INT8, "2", memory, io);
	cpu.execCmd("div", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 1);
	res = memory.popHeadStack();
	cr_assert_eq(res->getType(), INT8);
	cr_assert_eq(res->toString(), "2");
	delete res;
}

Test(Cpu, cmd_mod)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;
	IOperand *res;

	cr_assert_any_throw(cpu.execCmd("mod", INT8, "0", memory, io));
	cpu.execCmd("push", INT8, "1", memory, io);
	cpu.execCmd("push", INT8, "1", memory, io);
	cpu.execCmd("mod", INT8, "0", memory, io);
	cr_assert_eq(memory.getStackSize(), 1);
	res = memory.popHeadStack();
	cr_assert_eq(res->getType(), INT8);
	cr_assert_eq(res->toString(), "0");
	delete res;
}

Test(Cpu, cmd_exit)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;

	cpu.execCmd("exit", INT8, "0", memory, io);
	cr_assert_eq(cpu.getExit(), true);
}

Test(Cpu, cmd_print)
{
	IO io;
	Parser parser;
	Cpu cpu;
	Memory memory;

	cr_assert_any_throw(cpu.execCmd("print", INT8, "0", memory, io));
	cpu.execCmd("push", INT16, "1", memory, io);
	cr_assert_any_throw(cpu.execCmd("print", INT8, "0", memory, io));
	cpu.execCmd("push", INT8, "1", memory, io);
	cr_assert_none_throw(cpu.execCmd("print", INT8, "0", memory, io));
}
