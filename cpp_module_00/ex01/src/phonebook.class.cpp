#include "../include/info.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "phonebook constructor called \n" << std::endl;
	this->i = 0;
}

Phonebook::~Phonebook(void)
{
	std::cout << "phonebook destructor called \n" << std::endl;
}

// Contact Phonebook::create_contact(void)
// {
// 	Contact	instance;

// 	instance.Set_first_name();
// 	instance.Set_last_name();
// 	instance.Set_nick_name();
// 	instance.Set_phone_number();
// 	instance.Set_darkest_secret();
// 	return (instance);
// }

// void Phonebook::add_contact(void)
// {

// 	this->contact_list[this->i] = create_contact();
// 	if (this->i < 7)
// 		this->i++;
// 	else if (this->i == 7)
// 		this->i = 0;
// }

void Phonebook::add_contact(void)
{
	Contact &existing_contact = this->contact_list[this->i];
	existing_contact.Set_first_name();
	existing_contact.Set_last_name();
	existing_contact.Set_nick_name();
	existing_contact.Set_phone_number();
	existing_contact.Set_darkest_secret();
	if (this->i < 7)
		this->i++;
	else if (this->i == 7)
		this->i = 0;
}

void	Phonebook::show_contacts(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;

	std::cout << std::right
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First name" << "|"
		<< std::setw(10) << "Last name" << "|"
		<< std::setw(10) << "Nick name" << "|" <<std::endl;

	for (int c = 0; c < 8; c++)
	{
		first_name = this->contact_list[c].Get_first_name();
		last_name = this->contact_list[c].Get_last_name();
		nick_name = this->contact_list[c].Get_nick_name();
		std::cout << std::right <<std::setw(10) << (c + 1) << "|";
		first_name = CheckLen(first_name);
		std::cout << std::right << std::setw(10) << first_name << "|";
		last_name = CheckLen(last_name);
		std::cout << std::right << std::setw(10) << last_name << "|";
		nick_name = CheckLen(nick_name);
		std::cout << std::right << std::setw(10) << nick_name << "|" << std::endl;
	}
	
}

void	Phonebook::show_full_contact(int i)
{
	if (this->contact_list[i].Get_first_name().empty())
	{
		(std::cout << "Contact has yet to be filled in" << std::endl);
		return ;
	}
	std::cout << "First name: " << this->contact_list[i].Get_first_name() << std::endl;
	std::cout << "Last name: " << this->contact_list[i].Get_last_name() << std::endl;
	std::cout << "Nick name: " << this->contact_list[i].Get_nick_name() << std::endl;
	std::cout << "Phone number: " << this->contact_list[i].Get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->contact_list[i].Get_darkest_secret() << std::endl;
}

void	Phonebook::Search(void)
{
	std::string user_input_string;
	int			user_input_index;

	this->show_contacts();
	std::cout << "Enter index of contact you are looking for" << std::endl;
	getline(std::cin, user_input_string);
	user_input_index = std::atoi(user_input_string.c_str());
	if (user_input_index > 0 && user_input_index < 9)
		this->show_full_contact((user_input_index - 1));
	else
		std::cout << "index not allowed, enter valid index please" << std::endl;
}