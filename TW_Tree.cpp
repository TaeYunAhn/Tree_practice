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

Node* TW_Tree::Find(int data)
{

    // 데이터가 현재 노드보다 작으면 왼쪽으로 find
    // 데이터가 현재 노드보다 크면 오른쪽으로 find

    Node* cur_node = Root;

    if (data == cur_node->data)
        return cur_node;

    if (data < cur_node->data)
    {
        cur_node = cur_node->left;
        TW_Tree::Find;
    }

    if (data > cur_node->data)
    {
        cur_node = cur_node->right;
        TW_Tree::Find;
    }
}

void TW_Tree::Del(int data)
{
    // 가장 마지막 노드(리프 노드) -> 삭제
    // 자식 노드가 하나인 노드
    // 자식 노드가 두개인 노드
    Node* cur_node = TW_Tree::Find(data);
    TW_Tree::LeftisExist(cur_node);
    TW_Tree::RightisExist(cur_node);

    if (LeftisExist && RightisExist)
    {
        // 자식노드가 2개일 경우
        // 어떤 노드가 대체할지 결정
        //  - 왼쪽노드 : 왼쪽노드로 한번 진입 후 오른쪽 노드로 계속 진입하여 현재노드와 차이를 비교
        //  - 오른쪽 노드 : 오른쪽 노드 한번 진입후..... 현재노드와 차이를 위의 값과 비교
        // 두 값을 비교하여 차이가 적은 노드를 위로 올려보냄
        // 제거할 노드에 현재 노드의 데이터를 복사
        // 현재 노드를 대체할 노드를 복사 (자식노드들 까지 딸려오도록)  
        //
        //

        Node *left_node;
        Node *right_node;
        
        while (left_node->right == nullptr)
        {
            left_node = left_node->right;
        }

        while (right_node->left == nullptr)
        {
            right_node = right_node->left;
        }

        if ((cur_node->data - left_node->data) <= (right_node->data - cur_node->data))
        {
            cur_node->data = left_node->data;

        }
        else
        {
            cur_node = right_node;
        }
    }
    
    if ((!LeftisExist && RightisExist) || (LeftisExist && !RightisExist))
    {

    }
    
    if (!LeftisExist && !RightisExist)
        delete cur_node;
}

void TW_Tree::Callup(Node* cur_node)
{

}



bool TW_Tree::isExist(int data)
{
    if (TW_Tree::Find(data) == nullptr)
        return false;
    else
        return true;
}


bool TW_Tree::LeftisExist(Node* cur_node)
{
    cur_node = cur_node->left;
    if (TW_Tree::isExist(cur_node->data))
        return true;
    else
        return false;
}


bool TW_Tree::RightisExist(Node* cur_node)
{
    cur_node = cur_node->right;
    if (TW_Tree::isExist(cur_node->data))
        return true;
    else
        return false;
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