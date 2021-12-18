#include "family_mgr.h"

using namespace std;

void familymgr::addFamily(family& famPtr)
{
	ht.insert(famPtr);
}

void familymgr::printAllFamilies()
{
	ht.dumpTable();
}

void familymgr::printGroup()
{

}

void familymgr::printSmallCircle(const char id[64])
{
	family * foundFam = nullptr;
	family * temp = nullptr;
	cout << "Printing family and immediate friends " << id << endl;
	foundFam = ht.lookup(id);

	cout << "== Family ==" << endl;
	cout << *foundFam << endl;
	
	cout << "== Friends (1 level) ==" << endl;
        temp = ht.lookup(foundFam->getF1());
	if(temp != nullptr)
	{
		cout << *temp;
	}
	temp = ht.lookup(foundFam->getF2());
	if(temp != nullptr)
	{
		cout << *temp;
	}
	temp = ht.lookup(foundFam->getF3());
	if(temp != nullptr)
	{
        	cout << *temp;
	}
}
