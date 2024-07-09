
#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

std::string	truncate(std::string target)
{
	if (target.size() > 10)
		target = target.substr(0, 10);
	target[9] = '.';
	return (target);
}

int	main()
{
	PhoneBook	PhoneBook;

	while (1)
	{
		std::cout << "\n\n---------------------------------------------" << std::endl;
		std::cout << "		  MAIN MENU" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Please enter one of the following commands: " << std::endl;
		std::cout << "ADD\nSEARCH\nEXIT" <<std::endl;

		std::string	input;
		std::cout << "\nYour input: ";
		if (!getline(std::cin, input))
			exit(1);
		std::cout << "\n";
		if (input == "ADD")
			PhoneBook.add();
		if (input == "SEARCH")
			PhoneBook.search();
		if (input == "EXIT")
			exit_menu();
	}

	return (0);
}
