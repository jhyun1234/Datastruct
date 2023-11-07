#pragma once
#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

#pragma region 해시 테이블
// Key,Value 로 데이터를 저장하는 자료 구조 중 하나로
// 빠르게 데이터를 검색할 수 있는 자료 구조이다.

// 해시 테이블의 평균 시간 복잡도는 O(1)이다.

// <해시 충돌을 해결하는 방법>
// (1) 체이닝 기법
// 각 해시 버켓을 연결 리스트로 구성하는 방식이다.
// 해시 충돌 발생 시 동일한 해시 값에 해당하는 데이터들을
// 연결 리스트로 연결하여 저장한다.

// (2) 개방 주소법
// 충돌 발생 시 빈 버켓에 데이터를 저장하는 방식이다.
// 빈 버켓을 어떻게 결정할 지에 따라 구현 방식이 달라진다.

// 선형 탐사 : 충돌 발생 시 앞에서 부터 차례대로 빈 버켓을 찾아
//           값을 저장하는 방식이다.

// 이차 탐사 : 충돌 발생 시 2^,2^3 만큼 떨어진 빈 버킷을 찾아
//            값을 저장하는 방식이다.

// 이중 해싱 : 해시 값을 한번 더 해시 함수에 넣어 다른 함수를 
//            도출하는 방식이다.

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
		// 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 새로운 노드를 생성한다.
		Node* newNode = CreatNode(key, value);
		
		// 노드가 1개 라도 존재하지 않는다면
		if (bucket[hashIndex].count == 0)
		{
			// 1. buket[hashIndex]의 head 포인터에 새로운 노드의 주소값을 저장한다.
			bucket[hashIndex].head = newNode;

			// 2. buket[hashIndex]의 count 변수의 값을 증가시킨다.
			bucket[hashIndex].count++;

		}
		else // 노드가 1개라도 존재한다면
		{
			// 1. NewNode의 next에 bucket[hashIndex]의 head의 값을 넣어준다.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head를 방금 새로 생성한 노드의 주소를 가르키게 한다.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex].count 의 값을 증가시킨다.
			bucket[hashIndex].count++;
		}
	}

	void Remove(T key)
	{
		// 1. 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 2. Node를 탐색할 수 있는 순회용 포인터 변수 선언
		//    각 Bucket의 Head를 저장한다.
		Node* currentNode = bucket[hashIndex].head;

		// 3. 이전 Node를 저장할 수 있는 포인터 변수 선언
		Node* traceNode = nullptr;

		// 4. currentNode가 nullptr이라고 하면 함수를 종료한다.
		if (currentNode == nullptr)
		{
			cout << "HashTable is Empty" << endl;
			return;
		}
	
		// 5. currentNode를 이용해서 내가 찾고자 하는 key 값을 찾는다.
		while(currentNode != nullptr)
		{
			// currentNode->key 값과 내가 삭제하고 싶은 key값이 같다면
			if (currentNode->key == key)
			{
				// 내가 삭제하고자 하는 key가 head에 있는 노드라면
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
		
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				// 각 bucket의 카운트를 감소시킨다.

				bucket[hashIndex].count--;

				// 해당 메모리를 삭제한다.

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

