#pragma once
#include <iostream>

using namespace std;
#define SIZE 5
template <typename T>
class Linear
{
private:

	int front;
	int rear;
	int size;

	T buffer[SIZE];


public:

	Linear()
	{
		front = 0;
		rear = 0;
		size = 0;
	}
        
	void Enqueue(T data)
	{
		if (IsFull()==true)

		{
			cout << "Queue is Full" << endl;

		}
		else
		{
			buffer[rear++] = data;

			size++;
		}
	}
	
	void Dequeue()
	{
		if (Empty()==true)
		{
			cout << "Queue is Empty" << endl;

		}
		else
		{
			buffer[front++] = NULL;
			size--;
		}
	}

	bool IsFull()
	{
		if (SIZE <= rear)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool Empty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;

		}
	}

	int& Size()
	{
		return size;

	}

	T& Front()
	{
		if (Empty() == true)
		{
			exit(1);
		}
		else
		{
			return buffer[front];
		}
		
	}

	T& Back()
	{
		if (Empty() == true)
		{
			exit(1);
		}
		else
		{
			return buffer[rear - 1];
		}
		
	}
	~Linear() {}
};

