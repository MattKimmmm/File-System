#pragma once
#include "..\..\SharedCode\RenameParsingStrategy.h"


class newParsingStrategy : public AbstractParsingStrategy {

public:
	std::vector<std::string> parse(std::string) override;
};

