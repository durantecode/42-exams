#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget*>::iterator it = this->m_types.begin();
	std::vector<ATarget*>::iterator ite = this->m_types.end();
	while (it != ite)
	{
		delete *it;
		it++;
	}
	this->m_types.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
	{
		std::vector<ATarget*>::iterator it = this->m_types.begin();
		std::vector<ATarget*>::iterator ite = this->m_types.end();
		while (it != ite)
		{
			if ((*it)->getType() == target->getType())
				return;
			it++;
		}
		this->m_types.push_back(target->clone());
	}
}

void TargetGenerator::forgetTargetType(const std::string &targetType)
{
	std::vector<ATarget*>::iterator it = this->m_types.begin();
	std::vector<ATarget*>::iterator ite = this->m_types.end();
	while (it != ite)
	{
		if ((*it)->getType() == targetType)
		{
			delete *it;
			it = this->m_types.erase(it);
		}
		it++;
	}
}

ATarget *TargetGenerator::createTarget(const std::string &targetType)
{
	std::vector<ATarget*>::iterator it = this->m_types.begin();
	std::vector<ATarget*>::iterator ite = this->m_types.end();
	while (it != ite)
	{
		if ((*it)->getType() == targetType)
			return (*it);
		it++;
	}
	return (nullptr);
}
