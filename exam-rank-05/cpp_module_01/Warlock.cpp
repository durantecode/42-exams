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

	std::vector<ASpell*>::iterator it = this->m_spells.begin();
	std::vector<ASpell*>::iterator ite = this->m_spells.end();
	while (it != ite)
	{
		delete *it;
		it++;
	}
	this->m_spells.clear();
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

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		std::vector<ASpell*>::iterator it = this->m_spells.begin();
		std::vector<ASpell*>::iterator ite = this->m_spells.end();
		while (it != ite)
		{
			if ((*it)->getName() == spell->getName())
				return;
			it++;
		}
		this->m_spells.push_back(spell->clone());
	}
}

void Warlock::forgetSpell(const std::string &spellName)
{
	std::vector<ASpell*>::iterator it = this->m_spells.begin();
	std::vector<ASpell*>::iterator ite = this->m_spells.end();
	while (it != ite)
	{
		if ((*it)->getName() == spellName)
		{
			delete *it;
			it = this->m_spells.erase(it);
		}
		it++;
	}
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target)
{
	std::vector<ASpell*>::iterator it = this->m_spells.begin();
	std::vector<ASpell*>::iterator ite = this->m_spells.end();
	while (it != ite)
	{
		if ((*it)->getName() == spellName)
			(*it)->launch(target);
		it++;
	}
}
