#pragma once

#include <iostream>

using namespace std;

#pragma region 이진 탐색 트리 (BST)
// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데
// 효율적인 알고리즘입니다.
#pragma region 트리
// 편향 이진 트리
// 하나의 차수로만 이루어져 있는 트리

// 포화 이진 트리
// left Node를 제외한 모든 노드의 차수가
// 2개로 이루어져 있는 트리

// 완전 이진 트리
// 모든 노드가 왼쪽부터 차근차근 생성되는 이진 트리

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
        
        else if (root->data > data) // root의 data보다 작다면?
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

    

};