#ifndef AUTHORITY_H
#define AUTHORITY_H
#include <string>

struct Authority{
	std::string branch;
	std::string nextBranch;
	int endBlock;
};

#endif
