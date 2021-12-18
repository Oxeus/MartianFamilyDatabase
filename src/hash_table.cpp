#include "hash_table.h"
#include <cmath>
#include <cstring> 

hashtable::hashtable()
{
	htable = nullptr;
	htable = new node*[MAX];
	for (int i = 0; i < MAX; i++)
	{
		htable[i] = nullptr;
	}
}

hashtable::hashtable(const int HASHTABLESIZE)
{
	MAX = HASHTABLESIZE;
	htable = nullptr;
	htable = new node*[MAX];
	for (int i = 0; i < MAX; i++)
	{
		htable[i] = nullptr;
	}
}

hashtable::~hashtable()
{
	for (int i = 0; i < MAX; ++i)
	{
		node* curr = htable[i];
		node* next;
		while (curr != nullptr)
		{
			next = curr->next;
			delete curr->fam;
			delete curr;
			curr = next;
		}
	}
	delete[] htable;
}

size_t hashtable::getkey(const char * id)
{
	int n = strlen(id);
	size_t key = 0;
	for (int j = 0; j < n; j++)
	{
		key = (32 * key + id[j]);
	}
	return key;
}

size_t hashtable::hashcode(size_t key)
{
	return (key % MAX);
}

void hashtable::insert(family& familyPtr)
{
	node * temp = new node;
	temp->fam = new family;
	*temp->fam = familyPtr;
	temp->key = getkey(temp->fam->getId());
	temp->next = nullptr;
	size_t index = hashcode(temp->key);
	if (htable[index] == nullptr)
	{
		htable[index] = temp;
	}
	else
	{
		temp->next = htable[index];
		htable[index] = temp;
	}
} 

family* hashtable::lookup(const char * id)
{
	family* temp = nullptr;
	size_t key = getkey(id);
	size_t index = hashcode(key);
	if (index < MAX)
	{
		node * curr = htable[index];
		while (curr)
		{
			if (curr->key == key)
			{
				temp = curr->fam;
			}
			curr = curr->next;
		}
	}
	else
	{
		temp = nullptr;
	}
	return temp;
}
	
void hashtable::dumpTable()
{
	for (int i = 0; i < MAX; i++)
	{
		node * curr = htable[i];
		cout << "table[" << i << "]" << endl;
		cout << "List: " << endl;
		while (curr)
		{
			cout << *curr->fam;
			curr = curr->next;
		}
		cout << "--------------------" << endl;
	}
}
