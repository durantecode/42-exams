#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string m_name;
		std::string m_effects;
	
	public:
		ASpell();
		ASpell(const std::string &name, const std::string &effects);
		virtual ~ASpell();
		ASpell(ASpell const &toCopy);
		ASpell &operator = (ASpell const &toCopy);
		
		const std::string &getName() const;
		const std::string &getEffects() const;

		virtual ASpell *clone() const = 0;
		
		void launch(const ATarget &target) const;
};
