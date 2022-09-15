#pragma once

#include <iostream>

class Warlock
{
	private:
		std::string m_name;
		std::string m_title;
		Warlock();
		Warlock(Warlock const &toCopy);
		Warlock &operator = (Warlock const &toCopy);
	
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
	
		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
};
