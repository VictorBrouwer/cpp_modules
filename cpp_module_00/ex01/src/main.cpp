#include "../include/info.hpp"

int	main(void)
{
	std::string	user_input;
	Phonebook book;

	while (1)
	{
		std::cout << "enter a command (ADD to save a new contact, SEARCH to display contacts, or EXIT to quit)" <<std::endl;
		getline(std::cin, user_input);
		if (user_input == "ADD")
			book.add_contact();
		else if (user_input == "SEARCH")
			book.Search();
		else if (user_input == "EXIT")
			return (0);
		else
			std::cout << "command not found" << std::endl;
	}
}