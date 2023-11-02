#include <iostream>
#include "MaxHeap.h"


using namespace std;


int main()
{
	MaxHeap<int> maxheap;
	maxheap.Insert(30);
	maxheap.Insert(40);
	maxheap.Insert(15);
	maxheap.Insert(31);
	maxheap.Insert(55);

	maxheap.DisPlay();
	return 0;


}