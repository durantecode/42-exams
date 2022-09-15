#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::~ATarget() {}

ATarget::ATarget(const std::string &type)
{
	this->m_type = type;
}

ATarget::ATarget(ATarget const &toCopy)
{
	*this = toCopy;
}

ATarget &ATarget::operator=(ATarget const &toCopy)
{
	this->m_type = toCopy.getType();
	return *this;
}

const std::string &ATarget::getType() const
{
	return (this->m_type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->m_type << " has been " << spell.getEffects() << "!" << std::endl;
}
