
#include <iomanip>
#include <iostream>
#include "PhoneBook.hpp"
#include <cstdlib>

void	exit_menu()
{
	std::cout << "Warning: If you exit, all contacts will be lost. Proceed to exit?" << std::endl;
	std::string	response;
	do
	{
		std::cout << "Select yes/no: ";
		if (!getline(std::cin, response))
			exit (1);
		if (!(response == "yes" || response == "no"))
		{
			std::cerr << "Error: Please enter a valid reponse" << std::endl;
			continue ;
		}
		if (response == "yes")
			exit (0);
		else
			break ;
	} while (1);
	std::cout << "\n";
}
