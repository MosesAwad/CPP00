
#include <iomanip>
#include <iostream>
#include "PhoneBook.hpp"
#include <cstdlib>

/*
	The setw(10) function ensures that the entry is at least 10 
	characters wide by padding it with spaces if it is shorter than
	10 characters, but if the entry is longer than 10 characters, it
	does not truncate it. That is why I manually truncate while 
	displaying the entries via my truncate() function which is defined
	in main.cpp.
*/
void	search(PhoneBook& PhoneBook)
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "F_Name" << "|"
				<< std::setw(10) << "L_Name" << "|"
				<< std::setw(10) << "N_name" << "|" << std::endl;
	std::cout	<< "--------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++) {
		if (PhoneBook.list[i].index == -1)
			break ;
		std::cout	<< std::setw(10) << std::string(1, (PhoneBook.list[i].index + '0')) << "|"
					<< std::setw(10) << truncate(PhoneBook.list[i].first_name) << "|"
					<< std::setw(10) << truncate(PhoneBook.list[i].last_name) << "|"
					<< std::setw(10) << truncate(PhoneBook.list[i].nickname) << "|"
					<< std::endl;
					std::cout << "--------------------------------------------" << std::endl;
	}

	std::cout << "\n";
	long long	index_int;
	do
	{
		if (PhoneBook.list[0].index == -1)
		{
			std::cerr << "Error: Couldn't fetch contacts, contact list empty\n" << std::endl;
			break ;
		}
		std::cout << "Select the index of the contact you would like to view: ";
		std::string	index_str;
		if (!getline(std::cin, index_str))
			exit(1);
		bool flag = false;
		for (size_t i = 0; i < index_str.size(); i++) {
			if (isdigit(index_str[i]) == false)
			{
				std::cerr << "Error: Invalid argument. Please try again\n" << std::endl;
				flag = true;
				break ;
			}
		}
		if (flag == true)
			continue ;
		const char *c_index_str = index_str.c_str();
		index_int = atol(c_index_str);
		if (index_int < 0 || index_int >= 8)
		{
			std::cerr << "Error: Must select a value between 0-7. Please try again\n" << std::endl;
			continue ;
		}
		if (PhoneBook.list[index_int].index != -1)
		{
			std::cout << "\nYour selection: " << index_int << " [" << PhoneBook.list[index_int].first_name << "]" << std::endl;
			std::cout << "\n";
			std::cout << "First Name: " << PhoneBook.list[index_int].first_name << std::endl;
			std::cout << "Last Name: " << PhoneBook.list[index_int].last_name << std::endl;
			std::cout << "Nickname: " << PhoneBook.list[index_int].nickname << std::endl;
			std::cout << "\n";
			break ;
		}
		else
		{
			std::cerr << "Error: This field is empty. Please select a valid index\n" << std::endl;
			continue ;
		}
	} while (1);
}
