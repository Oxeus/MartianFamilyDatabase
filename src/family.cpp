#include <iostream>
#include "family.h"
#include <cstring>

using namespace std;

family::family()
{
	id[20] = '\0';
	name[20] = '\0';
	number = '\0';
	F1[20] = '\0';
	F2[20] = '\0';
	F3[20] = '\0';
}

family::family(const char newID[], const char newName[], int num)
{
	strcpy(id, newID);
	strcpy(name, newName);
	number = num;
	strcpy(F1, "");
	strcpy(F2, "");
	strcpy(F3, "");
}

family::~family()
{

}

bool family::addFriend(const char* newFriend)
{
	bool temp = true;
	if (c == 0) 
	{
		
		strcpy(F1, newFriend);
		temp = true;
	}
	else if (c == 1)
	{
		strcpy(F2, newFriend);
		temp = true;
	}
	else if (c == 2)
	{
		strcpy(F3, newFriend);
		temp = true;
	}
	else
	{
		temp = false;
	}
	c++;
	return temp;
}

char* family::getId()
{
	return id;
}

char* family::getF1()
{
	return F1;
}

char* family::getF2()
{
	return F2;
}

char* family::getF3()
{
	return F3;
}

ostream& operator<< (ostream& os, const family& fam)
{
	os << "Family ID : " << fam.id << endl
		<< "  Name : " << fam.name << endl
		<< "  Members : " << fam.number << endl
		<< "  Friends : " << fam.F1 << " " << fam.F2 << " " << fam.F3 << endl;
	return os;
}
