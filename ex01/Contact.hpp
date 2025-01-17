
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	private:
		int				index;
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		long long		phone_number;
		std::string		darkest_secret;
	public:
		Contact() : index(-1) {};
		int&				get_index();
		std::string&		get_first_name();
		std::string&		get_last_name();
		std::string&		get_nickname();
		long long&			get_phone_number();
		std::string&		get_darkest_secret();
		void				set_index(int& index);
		void				set_first_name(std::string& first_name);
		void				set_last_name(std::string& last_name);
		void				set_nickname(std::string& nickname);
		void				set_phone_number(long long& phone_number);
		void				set_darkest_secret(std::string& darkest_secret);
};

#endif