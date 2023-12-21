#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include "info.hpp"

class Contact {

	private:

		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string	phone_number;
		std::string darkest_secret;

	public:

		void	Set_first_name();
		void	Set_last_name();
		void	Set_nick_name();
		void	Set_phone_number();
		void	Set_darkest_secret();

		std::string	Get_first_name() const;
		std::string	Get_last_name() const;
		std::string	Get_nick_name() const;
		std::string	Get_phone_number() const;
		std::string	Get_darkest_secret() const;

		Contact(void);
		~Contact(void);
};

#endif