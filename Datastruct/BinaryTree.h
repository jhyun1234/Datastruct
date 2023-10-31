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
	// 1. 새로운 노드를 생성한다.

	TreeNode* newNode = new TreeNode();

	// 2. 새로운 노드의 data 값을 저장한다.
	newNode->data = data;

	// 3. 새로운 노드의 left 값을 저장한다.
	newNode->left = left;

	// 4. 새로운 노드의 right 값을 저장한다.
	newNode->right = right;

	// 5. 새로운 노드의 주솟값을 반환한다.
	return newNode;


}

// 전위 순회
// 1. Root Node를 방문한다.
// 2. 왼쪽 서브 트리를 전위 순회한다.
// 3. 오른쪽 서브 트리를 전위 순회한다.
void Preorder(TreeNode* root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}

}



// 중위 순회
// 1. 왼쪽 서브 트리를 전위 순회한다.
// 2. Root Node를 방문한다.
// 3. 오른쪽 서브 트리를 전위 순회한다.
void Inorder(TreeNode* root)
{
	if (root != nullptr)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}


// 후위 순회
// 1. 왼쪽 서브 트리를 전위 순회한다.
// 2. 오른쪽 서브 트리를 전위 순회한다.
// 3. Root Node를 방문한다.
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
#pragma region 트리
	// 그래프의 일종으로 정점과  간선을
	// 이용하여 데이터의 배치 형태를 추상화한 자료 구조이다.

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