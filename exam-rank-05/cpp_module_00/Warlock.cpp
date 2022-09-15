#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
{
	this->m_name = name;
	this->m_title = title;
	std::cout << this->m_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->m_name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return (this->m_name);
}

const std::string &Warlock::getTitle() const
{
	return (this->m_title);
}

void Warlock::setTitle(const std::string &title)
{
	this->m_title = title;
}
	
void Warlock::introduce() const
{
	std::cout << this->m_name << ": I am " << this->m_name << ", " << this->m_title << "!" << std::endl;
}
