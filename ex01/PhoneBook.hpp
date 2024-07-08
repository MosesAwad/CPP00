
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

#endif