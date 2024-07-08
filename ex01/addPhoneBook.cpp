
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <cstdlib>

void	add(PhoneBook& PhoneBook)
{
	int	i;

	i = PhoneBook.contact_count % 8;
	PhoneBook.list[i].index = i;
	bool flag = false;

	// Obtain first name entry and parse for empty strings and make sure entry is no longer than 10 characters wide
	do
	{
		std::cout << "Please input a first name: ";
		if (!getline(std::cin, PhoneBook.list[i].first_name))
			exit(1);
		if (PhoneBook.list[i].first_name == "")
			std::cerr << "Error: Field cannot be empty\n" << std::endl;
		else
			flag = true;
		if (PhoneBook.list[i].first_name.size() > 10)
			PhoneBook.list[i].first_name = PhoneBook.list[i].first_name;
	} while (flag == false);

	// Obtain last name entry and parse for empty strings and make sure entry is no longer than 10 characters wide
	flag = false;
	do
	{
		std::cout << "Please input a last name: ";
		if (!getline(std::cin, PhoneBook.list[i].last_name))
			exit(1);
		if (PhoneBook.list[i].last_name == "")
			std::cerr << "Error: Field cannot be empty\n" << std::endl;
		else
			flag = true;
		if (PhoneBook.list[i].last_name.size() > 10)
			PhoneBook.list[i].last_name = PhoneBook.list[i].last_name;
	} while (flag == false);

	// Obtain nickname entry and parse for empty strings and make sure entry is no longer than 10 characters wide
	do
	{
		std::cout << "Please input a nickname: ";
		if (!getline(std::cin, PhoneBook.list[i].nickname))
			exit(1);
		if (PhoneBook.list[i].nickname == "")
			std::cerr << "Error: Field cannot be empty\n" << std::endl;
		else
			flag = true;
		if (PhoneBook.list[i].nickname.size() > 10)
			PhoneBook.list[i].nickname = PhoneBook.list[i].nickname;
	} while (flag == false);

	// Obtain phone number entry and parse for empty strings, non-digit entries, & out of range entries
	flag = false;
	do
	{
		std::string	phone_number_str;
		std::cout << "Please input a phone number: ";
		if (!getline(std::cin, phone_number_str))
			exit(1);
		if (phone_number_str == "")
		{
			std::cerr << "Error: Field cannot be empty\n" << std::endl;
			continue ;
		}

		bool flag = false;
		for (size_t i = 0; i < phone_number_str.size(); i++) {
			if (isdigit(phone_number_str[i]) == false)
			{
				std::cerr << "Error: Phone number must include digits only. Please try again\n" << std::endl;
				flag = true;
				break ;
			}
		}
		if (phone_number_str.size() >= 19)
		{
			std::cerr << "Error: Phone numbers longer than 18 digits cannot be accepted\n" << std::endl;
			flag = true;
		}
		if (flag == true)
			continue ;

		long long	phone_number_long;
		const char *c_phone_number_str = phone_number_str.c_str();
		phone_number_long = atol(c_phone_number_str);
		PhoneBook.list[i].phone_number = phone_number_long;
		break ;
	} while (1);

	// Obtain darkest secret entry and parse for empty strings
	flag = false;
	do
	{
		std::cout << "Please type in your darkest secret: ";
		if (!getline(std::cin, PhoneBook.list[i].darkest_secret))
			exit(1);
		if (PhoneBook.list[i].last_name == "")
			std::cerr << "Error: Field cannot be empty\n" << std::endl;
		else
			flag = true;
	} while (flag == false);

	// Update the contact count upon success of all contact-related entries
	PhoneBook.contact_count++;
	std::cout << "\n";
}
