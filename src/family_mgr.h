#pragma once
#include "family.h"
#include "hash_table.h"

class familymgr {
public:
	void addFamily(family& famPtr);
	void printAllFamilies();
	void printGroup();
	void printSmallCircle(const char id[64]);
private:
	hashtable ht;
};
