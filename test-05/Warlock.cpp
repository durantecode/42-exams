#include "Warlock.hpp"

Warlock::Warlock()
{

}

Warlock::Warlock(std::string name, std::string title) : m_name(name), m_title(title)
{
	std::cout << this->m_name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const &toCopy)
{

}

Warlock &Warlock::operator = (Warlock const &toCopy)
{

}

const std::string &Warlock::getName(void) const
{
	return (this->m_name);
}

const std::string &Warlock::getTitle(void) const
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

Warlock::~Warlock()
{
	std::cout << this->m_name << ": My job here is done!" << std::endl;
}