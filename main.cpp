#include <iostream>
#include "TW_Tree.h"

int main()
{
    TW_Tree tree;

    Node* root = tree.Add(nullptr, 5);
    root = tree.Add(root, 8);
    root = tree.Add(root, 11);
    root = tree.Add(root, 3);
    root = tree.Add(root, 21);

    std::cout << "Hello World!\n";
}