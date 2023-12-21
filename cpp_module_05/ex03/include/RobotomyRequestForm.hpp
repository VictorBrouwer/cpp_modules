#if !defined(RRF_HPP)
#define RRF_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm &rhs);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm();
	void	execute(Bureaucrat const & executor) const;
};




#endif // RRF_HPP
