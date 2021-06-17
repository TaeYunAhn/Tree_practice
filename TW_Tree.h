#include <string>
#pragma once

enum EN_POS
{
    preOrder,
    inOrder,
    PostOrder,
};


struct Node
{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node() {}
    Node(int data)
    {
        this->data = data;
    }

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class TW_Tree
{
public:

    TW_Tree();
    ~TW_Tree();

    void Add(int data);
    void Del(int data);
    Node* Find(int data);
    bool isExist(int data);
    bool LeftisExist(Node* cur_node);
    bool RightisExist(Node* cur_node);
    void Callup(Node* cur_node);
    void Print(EN_POS pos);
    Node* GetMax();
    Node* GetMin();

private:
    void AddRecursive(Node*& root, int data);
    Node Search(Node* cur_node, int data);
    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();
    void PreOrderRecursive(Node* cur_node);
    void InOrderRecursive(Node* cur_node);
    void PostOrderRecursive(Node* cur_node);


private:
    Node *Root;
};
