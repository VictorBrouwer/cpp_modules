#ifndef HARL_CLASS_H
# define HARL_CLASS_H

#include<iostream>
#include<string>

class Harl{
	public:
		void	complain(std::string level);
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
		// enum class LogLevel {
		// 	Debug,
		// 	Info,
		// 	Warning,
		// 	Error,
		// };
		// std::unordered_map<std::string, LogLevel> _lookuptable;
};


#endif