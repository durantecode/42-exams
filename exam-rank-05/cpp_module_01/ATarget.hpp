#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string m_type;
	
	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget(ATarget const &toCopy);
		ATarget &operator = (ATarget const &toCopy);
		virtual ~ATarget();
	
		const std::string &getType() const;

		virtual ATarget *clone() const = 0;
		
		void getHitBySpell(const ASpell &spell) const;
};
