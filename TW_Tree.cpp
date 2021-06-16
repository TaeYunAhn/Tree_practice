#include <iostream>
#include "TW_Tree.h"

using namespace std;


TW_Tree::TW_Tree()
{
    Root = nullptr;
}
TW_Tree::~TW_Tree()
{

}

void TW_Tree::Add(int data)
{
    return AddRecursive(Root, data);
}

void TW_Tree::AddRecursive(Node*& root, int data)
{
    // 1. �����Ͱ� ���� ��
    // 2. �����Ͱ� ��Ʈ���� ���� ��
    // 3. �����Ͱ� ��Ʈ���� Ŭ ��
    
    if ( root == nullptr )
    {
        Node *new_node = new Node(data);
        root = new_node;
    }
    else
    {
        if ( data < root->data )
            return AddRecursive( root->left, data );
        else
            return AddRecursive( root->right, data);
    }
}

void TW_Tree::Del(int data)
{
    // ���� ������ ���(���� ���) -> ����
    // �ڽ� ��尡 �ϳ��� ���
    // �ڽ� ��尡 �ΰ��� ���
}

Node* TW_Tree::Find(int data)
{
    // �����Ͱ� ���� ��庸�� ������ �������� find
    // �����Ͱ� ���� ��庸�� ũ�� ���������� find

    return nullptr;
}

bool TW_Tree::isExist(int data)
{

}

void TW_Tree::Print(EN_POS pos)
{
    switch ( pos )
    {
    case preOrder:
        PrintPreOrder();
        break;
    case inOrder:
        PrintInOrder();
        break;
    case PostOrder:
        PrintPostOrder();
        break;
    default:
        break;
    }
}

Node* TW_Tree::GetMax()
{
    return nullptr;
}

Node* TW_Tree::GetMin()
{
    return nullptr;
}

void TW_Tree::PrintPreOrder()
{
    Node n;
    Node* p = new Node;
    Node* p = Root;

    /*Node *Last_Node = Root;
    Node *node = Root;
    Node *up_node = Root;
    while ( Last_Node->right == nullptr )
    {
        Last_Node = Last_Node->right;
    }
    while ( node->right  == Last_Node->right)
    {
        node = node->left;

        while ( node->left == nullptr )
        {
            node = node->left;
            up_node = up_node->left;

            cout << node << endl;
        
            while ( node->right == nullptr )
            {
                node = up_node->right;
                cout << node << endl;
                cout << up_node << endl;
                node = up_node;

            }
        }
    }


    delete Last_Node;
    */

    PreOrderRecursive(Root);
    cout << endl;
}

void TW_Tree::PrintInOrder()
{
    InOrderRecursive(Root);
    cout << endl;
}

void TW_Tree::PrintPostOrder()
{
    PostOrderRecursive(Root);
    cout << endl;
}

void TW_Tree::PreOrderRecursive(Node* cur_node)
{
    if ( !cur_node )
        return;

    cout << cur_node->data << " "; // ���� ��� ���
    PreOrderRecursive(cur_node->left); // ���� ��� ���
    PreOrderRecursive(cur_node->right); // ������ ��� ���
}

void TW_Tree::InOrderRecursive(Node* cur_node)
{
    if ( !cur_node )
        return;

    InOrderRecursive(cur_node->left); // ���� ��� ���
    cout << cur_node->data << " "; // ���� ��� ���
    InOrderRecursive(cur_node->right); // ������ ��� ���
}

void TW_Tree::PostOrderRecursive(Node* cur_node)
{
    if ( !cur_node )
        return;

    PostOrderRecursive(cur_node->left); // ���� ��� ���
    PostOrderRecursive(cur_node->right); // ������ ��� ���
    cout << cur_node->data << " "; // ���� ��� ���
}