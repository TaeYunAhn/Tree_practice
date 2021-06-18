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



Node* TW_Tree::Find(int data)
{
    return FindRecursive(Root, data);


    // �����Ͱ� ���� ��庸�� ������ �������� find
    // �����Ͱ� ���� ��庸�� ũ�� ���������� find

   /* Node* cur_node = Root;

    if (data == cur_node->data)
        return cur_node;

    if (data < cur_node->data)
    {
        cur_node = cur_node->left;
        Find(cur_node->data);
    }

    if (data > cur_node->data)
    {
        cur_node = cur_node->right;
        Find(cur_node->data);
    }*/
}

Node TW_Tree::Search(Node* cur_node, int data)
{
    /*Node* cur_node = Root;
    if ( !cur_node )
        return;
    if ((cur_node->left->data == data) || (cur_node->right->data == data))
        return *cur_node;

    Search(cur_node->left, data);
    Search(cur_node->right, data);*/

    return Node();
}

// root부터 탐색해가면서 부모노드 저장하고 진행
// 재귀

void TW_Tree::Del(int data)
{
    // ���� ������ ���(���� ���) -> ����
    // �ڽ� ��尡 �ϳ��� ���
    // �ڽ� ��尡 �ΰ��� ���

    Node* cur_node = Root;
    Node* parent_node = nullptr;

    while ( cur_node != nullptr )
    {
        if ( cur_node->data == data )
            break;

        if ( cur_node->data < data )
        {
            parent_node = cur_node;
            cur_node = cur_node->right;
        }
        else
        {
            parent_node = cur_node;
            cur_node = cur_node->left;
        }
    }

    if ( cur_node == nullptr )
        return;

    if ( cur_node->left != nullptr && cur_node->right != nullptr )
    {
        // �ڽĳ�尡 2���� ���
        // � ��尡 ��ü���� ����
        //  - ���ʳ�� : ���ʳ��� �ѹ� ���� �� ������ ���� ��� �����Ͽ� ������� ���̸� ��
        //  - ������ ��� : ������ ��� �ѹ� ������..... ������� ���̸� ���� ���� ��
        // �� ���� ���Ͽ� ���̰� ���� ��带 ���� �÷�����
        // ������ ��忡 ���� ����� �����͸� ����
        // ���� ��带 ��ü�� ��带 ���� (�ڽĳ��� ���� ����������)
        //
        //
        //TW_Tree::Search(parent_node, data);


        Node *left_node = nullptr;
        Node *right_node = nullptr;

        while (left_node->right == nullptr)
            left_node = left_node->right;


        while (right_node->left == nullptr)
            right_node = right_node->left;


        if ((cur_node->data - left_node->data) <= (right_node->data - cur_node->data))
        {
            cur_node->data = left_node->data;
            delete left_node;
        }
        else
        {
            cur_node->data = right_node->data;
            delete right_node;
        }
    }

    if ( !cur_node->left && cur_node->right )
    {
        if ( cur_node->data < parent_node->data )
            parent_node->left = cur_node->right;
        else
            parent_node->right = cur_node->right;

        delete cur_node;
        return;
    }

    if ( cur_node->left && !cur_node->right )
    {
        if ( cur_node->data < parent_node->data )
            parent_node->left = cur_node->left;
        else
            parent_node->right = cur_node->left;

        delete cur_node;
        return;
    }

    if ( !cur_node->left && !cur_node->right )
    {
        if ( parent_node->data < cur_node->data )
            parent_node->right = nullptr;
        else
            parent_node->left = nullptr;

        delete cur_node;
        return;
    }
}

void TW_Tree::Callup(Node* cur_node)
{

}



bool TW_Tree::isExist(int data)
{
    return Find(data) != nullptr;
}


//bool TW_Tree::LeftisExist(Node* cur_node)
//{
//    cur_node = cur_node->left;
//    if (isExist(cur_node->data))
//        return true;
//    else
//        return false;
//}
//
//
//bool TW_Tree::RightisExist(Node* cur_node)
//{
//    cur_node = cur_node->right;
//    if (isExist(cur_node->data))
//        return true;
//    else
//        return false;
//}


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

Node* TW_Tree::GetMax(Node *cur_node)
{
    while (!cur_node ) 
        cur_node = cur_node->right;
    return (cur_node);
    
}

Node* TW_Tree::GetMin(Node *cur_node)
{
    return nullptr;
}

void TW_Tree::PrintPreOrder()
{
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

Node* TW_Tree::FindRecursive(Node* cur_node, int data)
{
    if ( cur_node == nullptr )
        return nullptr;

    if (data == cur_node->data)
        return cur_node;

    if (data < cur_node->data)
    {
        cur_node = cur_node->left;
        return FindRecursive(cur_node, data);
    }
    else
    {
        cur_node = cur_node->right;
        return FindRecursive(cur_node, data);
    }
}