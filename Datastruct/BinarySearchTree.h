#pragma once
#include <iostream>

using namespace std;

#pragma region ���� Ž�� Ʈ�� (BST)
// ������ Ű�� ���� ���Ҹ� ����, ����, �˻��ϴµ�
// ȿ������ �˰����̴�.


#pragma endregion

// ���� ���� Ʈ��
// �ϳ��� �����θ� �̷���� �ִ� Ʈ��

// ��ȭ ���� Ʈ��
// left Node�� ������ ��� ����� ������
// 2���� �̷���� �ִ� Ʈ��

// ���� ���� Ʈ��
// ��� ��尡 ���ʺ��� �������� �����Ǵ� ���� Ʈ��






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