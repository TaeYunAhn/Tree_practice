#include "TW_Tree.h"


TW_Tree::TW_Tree()
{
    Root = nullptr;
}
TW_Tree::~TW_Tree()
{

}

Node* TW_Tree::Add(Node* root, int data)
{
    // 1. 데이터가 없을 때
    // 2. 데이터가 루트보다 작을 때
    // 3. 데이터가 루트보다 클 때
    
    if ( root == nullptr )
    {
        Node *new_node = new Node(data);
        root = new_node;
    }

    if ( data < root->data )
        return Add(root->left, data);
    else
        return Add(root->right, data);

    Root = root;
    return root;
}

void TW_Tree::Del(int data)
{

}
Node TW_Tree::Find(int data)
{

}
void TW_Tree::Print()
{

}
Node TW_Tree::GetMax()
{

}
Node TW_Tree::GetMin()
{

}