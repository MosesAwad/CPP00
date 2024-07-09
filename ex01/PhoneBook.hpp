
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	list[8];
		int		contact_count;
	public:
		PhoneBook() : contact_count(0) {};
		void		add();
		void		search();
};

// exitPhoneBook.cpp
void	exit_menu();

// main.cpp
std::string	truncate(std::string target);

#endif