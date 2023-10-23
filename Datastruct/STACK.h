#pragma once
#include <iostream>
#include <stack>

using namespace std;

#define SIZE 5

template <typename T> 
class STACK
{

private:
	int top;
	
	T buffer[SIZE];



public:
	STACK()
	{
		top = -1;
		
	}

	void Push(T data) // 인덱스 값을 변경시켜주기위해
	{
		if (IsFull())
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			buffer[++top] = data;
		}

	}
	void Pop()    
	{
		if (Empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			top--;
		}
	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;

		}
	}

	bool  IsFull()
	{
		if (SIZE - 1 <= top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Size()
	{
		// [] [] [] []
		return top + 1;

	}
	T & Top()
	{
		return buffer[top];
	}

	~STACK() {}
};

