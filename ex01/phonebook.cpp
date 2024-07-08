#include <iostream>
#include <iomanip>
#include <string>

class	Contact
{
	public:
		int				index;
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		int				phone_number;
		std::string		darkest_secret;
	
	Contact() : index(-1) {};
};


class	PhoneBook
{
	public:
		Contact	list[8];
		int		contact_count;

	PhoneBook() : contact_count(0) {};
};

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
		{
			int	i;

			i = PhoneBook.contact_count % 8;
			PhoneBook.list[i].index = i;
			bool flag = false;
			do
			{
				std::cout << "Please input a first name: ";
				if (!getline(std::cin, PhoneBook.list[i].first_name))
					exit(1);
				if (PhoneBook.list[i].first_name == "")
					std::cerr << "Error: Field cannot be empty\n" << std::endl;
				else
					flag = true;
			} while (flag == false);
			
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
			} while (flag == false);

			do
			{
				std::cout << "Please input a nickname: ";
				if (!getline(std::cin, PhoneBook.list[i].nickname))
					exit(1);
				if (PhoneBook.list[i].nickname == "")
					std::cerr << "Error: Field cannot be empty\n" << std::endl;
				else
					flag = true;
			} while (flag == false);

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

				//cannot catch (const std::invalid_argument& ia) error in this case
				//because stol would accept something like "985jbsdjb" and just set
				//it to 985jbsdjb. So we must manually parse the string.
				bool flag = false;
				for (size_t i = 0; i < phone_number_str.size(); i++) {
					if (std::all_of(phone_number_str.begin(), phone_number_str.end(), isdigit) == false)
					{
						std::cerr << "Error: Phone number must include digits only. Please try again\n" << std::endl;
						flag = true;
						break ;
					}
				}
				if (flag == true)
					continue ;

				long	phone_number_int;
				try
				{
					phone_number_int = stol(phone_number_str);
				}
				catch (const std::out_of_range& oor)
				{
					std::cerr << "Error: Invalid phone number. Please try again\n" << std::endl;
					continue ;
				}
				PhoneBook.list[i].phone_number = phone_number_int;
				break ;
			} while (1);

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

			PhoneBook.contact_count++;
			std::cout << "\n";
		}
		if (input == "SEARCH")
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
							<< std::setw(10) << PhoneBook.list[i].first_name << "|"
							<< std::setw(10) << PhoneBook.list[i].last_name << "|"
							<< std::setw(10) << PhoneBook.list[i].nickname << "|"
							<< std::endl;
							std::cout << "--------------------------------------------" << std::endl;
			}

			std::cout << "\n";
			int	index_int;
			do
			{
				std::cout << "Select the index of the contact you would like to view: ";
				std::string	index_str;
				if (!getline(std::cin, index_str))
					exit(1);
				try
				{
					index_int = stoi(index_str);
					if (index_int < 0 || index_int >= 8)
					{
						std::cerr << "Error: Must select a value between 0-7. Please try again\n" << std::endl;
						continue ;
					}
				}
				catch (const std::invalid_argument& ia)
				{
					std::cerr << "Error: Invalid argument. Please try again\n" << std::endl;
					continue ;
				} 
				catch (const std::out_of_range& oor)
				{
					std::cerr << "Error: Out of range, must select a value between 0-7. Please try again\n" << std::endl;
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
		if (input == "EXIT")
		{
			std::cout << "Warning: If you exit, all contacts will be lost. Proceed to exit?" << std::endl;
			std::string	response;
			do
			{
				std::cout << "Select yes/no: ";
				if (!getline(std::cin, response))
					exit(1);
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
	}

	return (0);
}
