
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	public:
		Contact	list[8];
		int		contact_count;

	PhoneBook() : contact_count(0) {};
};

// addPhoneBook.cpp
void	add(PhoneBook& PhoneBook);

// searchPhoneBook.cpp
void	search(PhoneBook& PhoneBook);

// exitPhoneBook.cpp
void	exit_menu();

// main.cpp
std::string	truncate(std::string target);

#endif