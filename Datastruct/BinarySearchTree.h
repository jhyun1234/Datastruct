#pragma once

#include <iostream>

using namespace std;

#pragma region ���� Ž�� Ʈ�� (BST)
// ������ Ű�� ���� ���Ҹ� ����, ����, �˻��ϴµ�
// ȿ������ �˰����Դϴ�.
#pragma region Ʈ��
// ���� ���� Ʈ��
// �ϳ��� �����θ� �̷���� �ִ� Ʈ��

// ��ȭ ���� Ʈ��
// left Node�� ������ ��� ����� ������
// 2���� �̷���� �ִ� Ʈ��

// ���� ���� Ʈ��
// ��� ��尡 ���ʺ��� �������� �����Ǵ� ���� Ʈ��

#pragma endregion

#pragma endregion

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

public:
    Node* rootNode;

    BinarySearchTree()
    {
        rootNode = nullptr;
    }

    Node* GetRoot()
    {
        return rootNode;
    }

    Node* Insert(T data, Node* root)
    {
        if (Find(root, data) == true)
        {
            cout << "Duplicate Key" << endl;
            return root;
        }
        if (root == nullptr)
        {
            root = new Node;
            root->data = data;
            root->left = nullptr;
            root->right = nullptr;
        }
        
        else if (root->data > data) // root�� data���� �۴ٸ�?
        {
            root->left = Insert(data, root->left);
        }
        else
        {
            root->right = Insert(data, root->right);
        }
        
        return root;
    }

    bool Find(Node* root, T data)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else
        {
            if (root->data > data)
            {
                return Find(root->left, data);
            }
            else
            {
                return Find(root->right, data);
            }
        }
    }


    T& FindMax(Node* root)
    {
        if (root == nullptr)
        {
            cout << "Binary Search Tree is Empty" << endl;
            exit(1);
        }

        if (root->right == nullptr)
        {
            return root->data;
        }
        else
        {
            return FindMax(root->right);
        }
    }

    T& FindMin(Node* root)
    {
        if (root == nullptr)
        {
            cout << "Binary Search Tree is Empty" << endl;
            exit(1);
        }

        if (root->left == nullptr)
        {
            return root->data;
        }
        else
        {
            return FindMin(root->left);
        }
    }

    void Inorder(Node* root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
    }

    Node* MinValueNode(Node* root) // <- 
    {
        Node* currentNode = root;

        while (currentNode && currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }

        return currentNode;
    }

    Node* RemoveNode(Node* root, T data)
    {
        if (root == nullptr)
        {
            cout << "Not Key Found" << endl;
            return root;
        }

        if (root->data > data)
        {
            root->left = RemoveNode(root->left, data);
            

        }
        else if (root->data < data)
        {
           root->right = RemoveNode(root->right, data);
        }
        else // �����ϰ��� �ϴ� Key�� ã�Ҵ�.
        {
            // �ڽ� ��尡 �ϳ� ���� �� 
            // �ڽ� ��尡 �� �� ���� ��
            
            Node* tempNode;
            if (root->left == nullptr)
            {
                tempNode = root->right;
                delete root;
                return tempNode;
            }
            else if (root->right == nullptr)
            {
                tempNode = root->left;
                delete root;
                return tempNode;
            }

            // �ڽ� ��尡 �� �� ���� ��
            tempNode = MinValueNode(root->right);

            // ���� Node�� �����͸� �ٲ۴�.

            root->data = tempNode->data;


            // Node�� �����Ѵ�.
            
            root->right = RemoveNode(root->right, tempNode->data);
        }

        return root;

    }

};