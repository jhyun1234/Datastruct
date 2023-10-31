#pragma once
#include <iostream>

using namespace std;

struct TreeNode
{
	int data;

	TreeNode* right;
	TreeNode* left;

};

TreeNode* CreateNode(int data, TreeNode* left, TreeNode* right)
{
	// 1. ���ο� ��带 �����Ѵ�.

	TreeNode* newNode = new TreeNode();

	// 2. ���ο� ����� data ���� �����Ѵ�.
	newNode->data = data;

	// 3. ���ο� ����� left ���� �����Ѵ�.
	newNode->left = left;

	// 4. ���ο� ����� right ���� �����Ѵ�.
	newNode->right = right;

	// 5. ���ο� ����� �ּڰ��� ��ȯ�Ѵ�.
	return newNode;


}

// ���� ��ȸ
// 1. Root Node�� �湮�Ѵ�.
// 2. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
// 3. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
void Preorder(TreeNode* root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}

}



// ���� ��ȸ
// 1. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
// 2. Root Node�� �湮�Ѵ�.
// 3. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
void Inorder(TreeNode* root)
{
	if (root != nullptr)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}


// ���� ��ȸ
// 1. ���� ���� Ʈ���� ���� ��ȸ�Ѵ�.
// 2. ������ ���� Ʈ���� ���� ��ȸ�Ѵ�.
// 3. Root Node�� �湮�Ѵ�.
void Postorder(TreeNode* root)
{
	if (root != nullptr)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}


int main()
{
#pragma region Ʈ��
	// �׷����� �������� ������  ������
	// �̿��Ͽ� �������� ��ġ ���¸� �߻�ȭ�� �ڷ� �����̴�.

	TreeNode* node7 = CreateNode(7, nullptr, nullptr);
	TreeNode* node6 = CreateNode(6, nullptr, nullptr);
	TreeNode* node5 = CreateNode(5, nullptr, nullptr);
	TreeNode* node4 = CreateNode(4, nullptr, nullptr);
	TreeNode* node3 = CreateNode(3, node6, node7);
	TreeNode* node2 = CreateNode(2, node4, node5);
	TreeNode* node1 = CreateNode(1, node2, node3);


	Preorder(node1);

	cout << endl;

	Inorder(node1);

	cout << endl;
	Postorder(node1);


#pragma endregion



}