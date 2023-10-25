#pragma once
#include <iostream>

using namespace std;

#define SIZE 5
#define BUFFER 10
int main()
{
#pragma region ���� ť
	// �迭�� ������ �� �����Ͱ� �����Ǿ� �����͸�
	// �������� �ʱ�ȭ���� ������ ���� �����Ͱ� �ִ�
	// �迭�� �ڸ��� �� �̻� �ٸ� ���� �� �� ���� Queue �̴�.
	// 


	/*Linear<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);


	int size = queue.Size();
	for (int i = 0; i < size; i++)
	{
		cout << queue.Front() << " ";
		queue.Dequeue();
	}
	queue.Dequeue();*/


#pragma endregion

#pragma region ��� ����
	// �������� ���� ���� ������ �ʰ�, �ܼ��ϰ� �� ���ڰ�
	// �� �� �ִ��� ������ ���� ������ ���� �����ϴ� �˰����̴�.

	// �ð� ���⵵ : O(n + k)

	int buffer[BUFFER] = { 1,1,1,1,2,3,4,5,4,3 };

	int countBuffer[SIZE] = { 0, };

	for (int i = 0; i < BUFFER; i++)
	{
		countBuffer[buffer[i] - 1] += 1;
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << countBuffer[i] << endl;
	}



#pragma endregion

}