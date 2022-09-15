#pragma once

#include "ASpell.hpp"
#include <vector>

class SpellBook
{
	private:
		std::vector<ASpell*> m_book;
		SpellBook(SpellBook const &toCopy);
		SpellBook &operator = (SpellBook const &toCopy);
	
	public:
		SpellBook();
		~SpellBook();
	
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spellName);
		ASpell *createSpell(const std::string &spellName);
};
