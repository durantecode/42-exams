#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::vector<ASpell*>::iterator it = this->m_book.begin();
	std::vector<ASpell*>::iterator ite = this->m_book.end();
	while (it != ite)
	{
		delete *it;
		it++;
	}
	this->m_book.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		std::vector<ASpell*>::iterator it = this->m_book.begin();
		std::vector<ASpell*>::iterator ite = this->m_book.end();
		while (it != ite)
		{
			if ((*it)->getName() == spell->getName())
				return;
			it++;
		}
		this->m_book.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell(const std::string &spellName)
{
	std::vector<ASpell*>::iterator it = this->m_book.begin();
	std::vector<ASpell*>::iterator ite = this->m_book.end();
	while (it != ite)
	{
		if ((*it)->getName() == spellName)
		{
			delete *it;
			it = this->m_book.erase(it);
		}
		it++;
	}
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
	std::vector<ASpell*>::iterator it = this->m_book.begin();
	std::vector<ASpell*>::iterator ite = this->m_book.end();
	while (it != ite)
	{
		if ((*it)->getName() == spellName)
			return (*it);
		it++;
	}
	return (nullptr);
}
