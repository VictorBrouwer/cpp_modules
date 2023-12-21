#include "../include/info.hpp"

Contact::Contact (void)
{
	std::cout << "Contact default constructor called" << std::endl;
}

Contact::~Contact (void)
{
	std::cout << "Contact destructor called" << std::endl;
}

void	Contact::Set_first_name(void)
{
	this->first_name = GetAndCheckInput("Enter first name: ");
}

void	Contact::Set_last_name(void)
{
	this->last_name = GetAndCheckInput("Enter last name: ");
}

void	Contact::Set_nick_name(void)
{
	this->nick_name = GetAndCheckInput("Enter nick name: ");
}

void	Contact::Set_phone_number(void)
{
	this->phone_number = GetAndCheckInput("Enter phone number: ");
}

void	Contact::Set_darkest_secret(void)
{
	this->darkest_secret = GetAndCheckInput("Enter darkest secret: ");
}

std::string Contact::Get_first_name (void) const
{
	return (this->first_name);
}

std::string Contact::Get_last_name (void) const
{
	return (this->last_name);
}

std::string Contact::Get_nick_name (void) const
{
	return (this->nick_name);
}

std::string Contact::Get_phone_number (void) const
{
	return (this->phone_number);
}

std::string Contact::Get_darkest_secret (void) const
{
	return (this->darkest_secret);
}
