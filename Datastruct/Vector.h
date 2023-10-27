#pragma once
#include <iostream>

using namespace std;


template <typename T>
class Vector
{

private:
	int size;
	int capacity;

	T* bufferPointer;

public:

	Vector()
	{
		size = 0;
		capacity = 0;
		bufferPointer = nullptr;

	}
	void Resize(int nweSize)
	{
		// 1. capacity�� ���ο� size���� �����Ѵ�.
		capacity = newSize;

		// 2. ���ο� ������ ������ �����ؼ� ���Ӱ� �������
		//    �޸� ������ ����Ű���� �����Ѵ�.
		T* tempBuffer = new T[capacity];

		// 3. ���ο� �޸� ������ ���� �ʱ�ȭ �Ѵ�.
		for (int i = 0; i < capacity; i++)
		{
			tempBuffer[i] = NULL;
		}

		// 4. ���� �迭�� �ִ� ���� �����ؼ� ���ο� �迭��
		//    �־��ش�.

		for (int i = 0; i < size; i++)
		{
			tempBuffer[i] = bufferPointer[i];
		}

		// 5. bufferPointe�� �޸� �ּҸ� �����Ѵ�.
		if (bufferPointer != nullptr)
		{
			delete [] bufferPointer;
		}

		bufferPointer = tempBuffer;
		 
	}

	void PushBack(T data)
	{
		if (capacity == 0)
		{
			Resize(1);
		}
		else if(size >=capacity)
		{
			capacity = capacity * 2;

			Resize(capacity);
		}

		bufferPointer[size++] = data;
	}

	void PopBack(T data)
	{
		if(size==0)
		{

			

	    }
	}
	int Size()
	{
		return size;
	}

	bool IsFull()
	{

	}

	
};

