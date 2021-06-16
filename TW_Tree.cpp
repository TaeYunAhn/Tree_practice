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
    // 1. 데이터가 없을 때
    // 2. 데이터가 루트보다 작을 때
    // 3. 데이터가 루트보다 클 때
    
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
    // 가장 마지막 노드(리프 노드) -> 삭제
    // 자식 노드가 하나인 노드
    // 자식 노드가 두개인 노드
}

Node* TW_Tree::Find(int data)
{
    // 데이터가 현재 노드보다 작으면 왼쪽으로 find
    // 데이터가 현재 노드보다 크면 오른쪽으로 find

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

    cout << cur_node->data << " "; // 현재 노드 출력
    PreOrderRecursive(cur_node->left); // 왼쪽 노드 출력
    PreOrderRecursive(cur_node->right); // 오른쪽 노드 출력
}

void TW_Tree::InOrderRecursive(Node* cur_node)
{
    if ( !cur_node )
        return;

    InOrderRecursive(cur_node->left); // 왼쪽 노드 출력
    cout << cur_node->data << " "; // 현재 노드 출력
    InOrderRecursive(cur_node->right); // 오른쪽 노드 출력
}

void TW_Tree::PostOrderRecursive(Node* cur_node)
{
    if ( !cur_node )
        return;

    PostOrderRecursive(cur_node->left); // 왼쪽 노드 출력
    PostOrderRecursive(cur_node->right); // 오른쪽 노드 출력
    cout << cur_node->data << " "; // 현재 노드 출력
}