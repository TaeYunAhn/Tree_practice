#pragma once


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

    Node* Add(Node* root, int data);
    void Del(int data);
    Node Find(int data);
    void Print();
    Node GetMax();
    Node GetMin();

private:
    Node *Root;
};

