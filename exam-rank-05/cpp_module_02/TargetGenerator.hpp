#pragma once

#include "ATarget.hpp"
#include <vector>

class TargetGenerator
{
	private:
		std::vector<ATarget*> m_types;
		TargetGenerator(TargetGenerator const &toCopy);
		TargetGenerator &operator = (TargetGenerator const &toCopy);
	
	public:
		TargetGenerator();
		virtual ~TargetGenerator();
	
		void learnTargetType(ATarget *target);
		void forgetTargetType(const std::string &targetType);
		ATarget *createTarget(const std::string &targetType);
};
