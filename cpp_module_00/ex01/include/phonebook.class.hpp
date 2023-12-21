#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class Phonebook {
	public:
		Phonebook (void);
		~Phonebook (void);
		void	add_contact(void);
		void	Search(void);
		void	show_contacts(void);
		void	show_full_contact(int i);
	private:
		int		i;
		Contact	create_contact(void);
		Contact contact_list[8];
};

#endif