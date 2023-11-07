#include <iostream>
#include "HashTable.h"


using namespace std;


int main()
{
	HashTable<string, int> hashTable;

	hashTable.Insert("ABC", 100);
	hashTable.Insert("DEF", 200);
	hashTable.Insert("GHI", 300);
	hashTable.Insert("JKL", 400);
	hashTable.Insert("NMO", 500);

	hashTable.Display();


	return 0;


}