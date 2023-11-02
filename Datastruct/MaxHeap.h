#pragma once
#include <iostream>
using namespace std;

#define SIZE 8

template <typename T>
class MaxHeap
{
private:
	T heapBuffer[SIZE];
	int index;
		
public:
	Maxheap()
	{
		for (int i = 0; i < SIZE; i++)
		{
			heapBuffer[i] = NULL;
		}
		index = 0;

	}

	void Insert(T data)
	{
		if (IsFull() == true)
		{
			cout << "MaxHeap IS Full" << endl;
			return;
		}

		heapBuffer[++index] = data;

		int child = index;

		int parent = index / 2;

		while (child > 1)
		{
			// 자식 Node와 부모 Node의 데이터를 비교한다.
			if (heapBuffer[parent] < heapBuffer[child])
			{
				swap(heapBuffer[parent], heapBuffer[child]);
			}

			child = parent;
			parent = child / 2;

		}
		

	}

	bool IsFull()
	{
		if (index == SIZE - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void DisPlay()
	{
		for (T element : heapBuffer)
		{
			cout << element << " ";
		}
	}

};