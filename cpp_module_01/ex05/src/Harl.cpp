#include "../include/Harl.hpp"

// Harl::Harl()
// {
// 	_lookuptable["Debug"] = LogLevel::Debug;
// 	_lookuptable["Info"] = LogLevel::Info;
// 	_lookuptable["Warning"] = LogLevel::Warning;
// 	_lookuptable["Error"] = LogLevel::Error;
// }
void	Harl::debug (void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info (void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning (void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error (void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void	(Harl::*pointerFunction)(void);
	pointerFunction mpf;

	switch (level[0])
	{
	case 'D': {
		mpf = &Harl::debug;
		break;
	}
	case 'I': {
		mpf = &Harl::info;
				break;
	}
	case 'W': {
		mpf = &Harl::warning;
				break;
	}
	case 'E': {
		mpf = &Harl::error;
				break;
	}
	default: {
		mpf = 0;
		break;
		}
	}
	if (mpf != 0)
		(this->*mpf)();
}