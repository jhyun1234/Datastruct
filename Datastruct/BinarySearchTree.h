#pragma once
#include <iostream>

using namespace std;

#pragma region 이진 탐색 트리 (BST)
// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데
// 효율적인 알고리즘이다.


#pragma endregion

// 편향 이진 트리
// 하나의 차수로만 이루어져 있는 트리

// 포화 이진 트리
// left Node를 제외한 모든 노드의 차수가
// 2개로 이루어져 있는 트리

// 완전 이진 트리
// 모든 노드가 왼쪽부터 차근차근 생성되는 이진 트리






template <typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};


	Node* rootNode;

public:

	BinarySearchTree()
	{
		rootNode = nullptr;
	}

	Node* GetRoot()
	{
		return rootNode;
	}

	void Insert(T data, Node* root)
	{
		if (root == nullptr)
		{
			root = new Node<T>;
			root->data = data;
			root->left = nullptr;
			root->right = nullptr;
		}


	}


};