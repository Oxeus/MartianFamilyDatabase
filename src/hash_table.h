#pragma once
#include "family.h"

class node {
public:
	size_t key;
	family* fam;
	node* next;
};

class hashtable {
 public:
	 hashtable();
	 hashtable(const int HASHTABLESIZE);
	 ~hashtable();
	 size_t getkey(const char * id);
	 size_t hashcode(size_t key);
	 void insert(family& familyPtr);
	 family* lookup(const char * id);
	 void remove(const char * id);
	 void dumpTable();

 private:
	 node** htable;
	 int MAX = 7877;
};
