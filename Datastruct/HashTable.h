#pragma once
#include <iostream>
using namespace std;

#define SIZE 5

#pragma region �ؽ� ���̺�
// Key,Value �� �����͸� �����ϴ� �ڷ� ���� �� �ϳ���
// ������ �����͸� �˻��� �� �ִ� �ڷ� �����̴�.

// �ؽ� ���̺��� ��� �ð� ���⵵�� O(1)�̴�.

// <�ؽ� �浹�� �ذ��ϴ� ���>
// (1) ü�̴� ���
// �� �ؽ� ������ ���� ����Ʈ�� �����ϴ� ����̴�.
// �ؽ� �浹 �߻� �� ������ �ؽ� ���� �ش��ϴ� �����͵���
// ���� ����Ʈ�� �����Ͽ� �����Ѵ�.

// (2) ���� �ּҹ�
// �浹 �߻� �� �� ���Ͽ� �����͸� �����ϴ� ����̴�.
// �� ������ ��� ������ ���� ���� ���� ����� �޶�����.

// ���� Ž�� : �浹 �߻� �� �տ��� ���� ���ʴ�� �� ������ ã��
//           ���� �����ϴ� ����̴�.

// ���� Ž�� : �浹 �߻� �� 2^,2^3 ��ŭ ������ �� ��Ŷ�� ã��
//            ���� �����ϴ� ����̴�.

// ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؽ� �Լ��� �־� �ٸ� �Լ��� 
//            �����ϴ� ����̴�.

#pragma endregion


template <typename T, typename V>
class HashTable
{
private:
	struct Node
	{
		T key;
		V value;
		Node* next;

	};
	struct Bucket
	{
		Node* head;
		int count;

	};
	
	
	Bucket bucket[SIZE];
public:
	HashTable()
	{

		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}

	}

	int HashFunction(T key)
	{
		int sumValue = 0;
		if (T == string) 
		{
			for (const char& element : key)
			{
				sumValue += (int)element;

			}
			int hashIndex = sumValue % SIZE;

			return hashIndex;
		}
		
	}

	Node* CreatNode(T key, V value)
	{
		Node* newNode = new Node;
		
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;
		return newNode;
	}
	void Insert(T key, V value)
	{
		// �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// ���ο� ��带 �����Ѵ�.
		Node* newNode = CreatNode(key, value);
		
		// ��尡 1�� �� �������� �ʴ´ٸ�
		if (bucket[hashIndex].count == 0)
		{
			// 1. buket[hashIndex]�� head �����Ϳ� ���ο� ����� �ּҰ��� �����Ѵ�.
			bucket[hashIndex].head = newNode;

			// 2. buket[hashIndex]�� count ������ ���� ������Ų��.
			bucket[hashIndex].count++;

		}
		else // ��尡 1���� �����Ѵٸ�
		{
			// 1. NewNode�� next�� bucket[hashIndex]�� head�� ���� �־��ش�.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head�� ��� ���� ������ ����� �ּҸ� ����Ű�� �Ѵ�.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex].count �� ���� ������Ų��.
			bucket[hashIndex].count++;
		}
	}
};

