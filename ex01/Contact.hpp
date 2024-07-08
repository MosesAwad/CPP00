
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	public:
		int				index;
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		long long		phone_number;
		std::string		darkest_secret;
	
	Contact() : index(-1) {};
};

#endif