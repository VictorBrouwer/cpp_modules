#if !defined(PPF_HPP)
#define PPF_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm &rhs);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	~PresidentialPardonForm();
	void	execute(Bureaucrat const & executor) const;
};

#endif // PPF_HPP
