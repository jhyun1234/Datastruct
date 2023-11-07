#pragma once
#include <iostream>
#include <string>
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
	template<typename T>
	int HashFunction(T key)
	{

		int hashIndex = (int)key % SIZE;

		return hashIndex;


	}
	template<>
	int HashFunction(std::string key)
	{

		int sumValue = 0;
		
		
		for (const char& element : key)
		{
			sumValue += (int)element;

		}
		int hashIndex = sumValue % SIZE;

		return hashIndex;
		
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

	void Remove(T key)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// 2. Node�� Ž���� �� �ִ� ��ȸ�� ������ ���� ����
		//    �� Bucket�� Head�� �����Ѵ�.
		Node* currentNode = bucket[hashIndex].head;

		// 3. ���� Node�� ������ �� �ִ� ������ ���� ����
		Node* traceNode = nullptr;

		// 4. currentNode�� nullptr�̶�� �ϸ� �Լ��� �����Ѵ�.
		if (currentNode == nullptr)
		{
			cout << "HashTable is Empty" << endl;
			return;
		}
	
		// 5. currentNode�� �̿��ؼ� ���� ã���� �ϴ� key ���� ã�´�.
		while(currentNode != nullptr)
		{
			// currentNode->key ���� ���� �����ϰ� ���� key���� ���ٸ�
			if (currentNode->key == key)
			{
				// ���� �����ϰ��� �ϴ� key�� head�� �ִ� �����
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
		
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				// �� bucket�� ī��Ʈ�� ���ҽ�Ų��.

				bucket[hashIndex].count--;

				// �ش� �޸𸮸� �����Ѵ�.

				delete currentNode;

				return;
			}

			traceNode = currentNode;
			currentNode = currentNode->next;
		}
		
		cout << "Not key Found" << endl;

	}

	void Display()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* currentNode = bucket[i].head;

			while (currentNode != nullptr)
			{
				cout << "[" << i << "]" << "KEY :" << currentNode->key << "Value :" << currentNode->value << "--->";
				currentNode = currentNode->next;
			}
			cout << endl;
		}

	}
	~HashTable()
	{

	}
};

