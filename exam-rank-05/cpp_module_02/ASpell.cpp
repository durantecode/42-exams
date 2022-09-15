#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects)
{
	this->m_name = name;
	this->m_effects = effects;
}

ASpell::ASpell(ASpell const &toCopy)
{
	*this = toCopy;
}

ASpell &ASpell::operator=(ASpell const &toCopy)
{
	this->m_name = toCopy.getName();
	this->m_effects = toCopy.getEffects();
	return *this;
}

const std::string &ASpell::getName() const
{
	return (this->m_name);
}

const std::string &ASpell::getEffects() const
{
	return (this->m_effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
