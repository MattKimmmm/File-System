#pragma once
#include "AbstractParsingStrategy.h"


class RenameParsingStrategy : public AbstractParsingStrategy {

public:
	std::vector<std::string> parse(std::string) override;
};
