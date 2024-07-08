
#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

void	debugger(PhoneBook PhoneBook)
{
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "\t\tDEBUGGAGE" <<std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++) {
		if (PhoneBook.list[i].index == -1)
			break ;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << "This is PhoneBook[" << PhoneBook.list[i].index << "]'s first name: " << PhoneBook.list[i].first_name << std::endl;
		std::cout << "This is PhoneBook[" << PhoneBook.list[i].index << "]'s last name: " << PhoneBook.list[i].last_name << std::endl;
		std::cout << "This is PhoneBook[" << PhoneBook.list[i].index << "]'s nickname: " << PhoneBook.list[i].nickname << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	}
}

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
		std::cout << "Please enter one of the following commands: " << std::endl;
		std::cout << "ADD\nSEARCH\nEXIT" <<std::endl;

		std::string	input;
		std::cout << "\nYour input: ";
		if (!getline(std::cin, input))
			exit(1);
		std::cout << "\n";
		if (input == "ADD")
			add(PhoneBook);
		if (input == "SEARCH")
			search(PhoneBook);
		if (input == "EXIT")
			exit_menu();
	}

	return (0);
}
