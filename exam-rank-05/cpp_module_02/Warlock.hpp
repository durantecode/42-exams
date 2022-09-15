#pragma once

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string m_name;
		std::string m_title;
		SpellBook m_spellBook;

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
	
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spellName);
		void launchSpell(const std::string &spellName, const ATarget &target);
};
