#pragma once
#include <iostream>

using namespace std;

#define SIZE 8

template<typename T>
class MaxHeap
{
private:
	T heapBuffer[SIZE];
	int index;

public:
	MaxHeap()
	{
		for (int i = 0; i < SIZE; i++)
		{
			heapBuffer[i] = NULL;
		}

		index = 0;
	}

	void Insert(T data)
	{
		if (IsFull())
		{
			cout << "MaxHeap is Full" << endl;
			return;
		}

		heapBuffer[++index] = data;

		int child = index;
		int parent = index / 2;

		while (child > 1)
		{
			// �ڽ� ���� �θ� ����� �����͸� ���մϴ�.
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
			return true;
		else
			return false;
	}

	void Display()
	{
		for (const T& element : heapBuffer)
		{
			cout << element << " ";
		}
	}

	T & Delete()
	{
		// Heap�� ����ִٸ� ���α׷��� �����Ѵ�.
		if (index <= 0)
		{
			cout << "Heap is Empty" << endl;
			exit(1);
		}

		// �ӽ� ���� <- ���� ū ���� �����ϴ� ����
		T result = heapBuffer[1];

		// index �� ����Ű�� �迭�� ���� ù ��° ���ҿ� �־��ش�.
		heapBuffer[1] = heapBuffer[index];

		// index�� ����Ű�� �迭�� ���� �ʱ�ȭ �Ѵ�.
		heapBuffer[index] = NULL;

		// index�� ���� ���ҽ�Ų��.
		index--;

		int parent = 1;

		while (parent * 2 <=index)
		{
			int child = parent * 2;

			// ������ �ڽ��� ��尡 Ŭ ��
			if (heapBuffer[child] < heapBuffer[child + 1])
			{
				child++;
			}

			// �θ� ����� Key ���� �ڽ� ����� Key ������ ũ�ٸ� �ݺ��� �����Ѵ�.

			if (heapBuffer[child] < heapBuffer[parent])
			{
				break;
			}

			swap(heapBuffer[parent], heapBuffer[child]);
			parent = child;

			
		}

		return result;

	}
};