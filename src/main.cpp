/*
** EPITECH PROJECT, 2018
** SYN_abstractVM_2017
** File description:
** main
*/

#include "Chipset.hpp"

int	main(int ac, char **av)
{
	IO io;
	std::string input;

	try{
		if (ac == 1)
			io.readStandard();
		else
			io.readFile(av[1]);
		Chipset	chipset(input, io);
		for (size_t i = 0; i != io.getSize(); i++){
			chipset.setInput(io.getNextLine());
			chipset.translateAndExecute();
		}
		chipset.verifExit();
	}
	catch (AbstractException const& error){
		std::cerr << error.what();
		return 84;
	}
	return 0;
}