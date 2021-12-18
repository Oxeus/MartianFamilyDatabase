#pragma once
#include <iostream>
using namespace std;

class family {
public:
	family();
	family(const char newID[], const char newName[], int num);
	~family();

	char* getId();
	char* getF1();
	char* getF2();
	char* getF3();
	bool addFriend(const char* newFriend1);

	friend ostream& operator<< (ostream& os, const family& fam);
private:
	int MAXSIZE = 3;
	int c = 0;
	char id[100];
	char name[100];
	int number;
	char F1[100];
	char F2[100];
	char F3[100];
};
