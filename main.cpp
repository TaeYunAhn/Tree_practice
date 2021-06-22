#include <iostream>
#include "TW_Tree.h"

int main()
{
    TW_Tree tree;
    tree.Add(20);
    tree.Add(10);
    tree.Add(5);
    tree.Add(15);
    tree.Add(30);
    tree.Add(25);
    tree.Add(35);
    tree.Add(27);

    std::cout << "전위 순회: ";
    tree.Print(preOrder);
    std::cout << "중위 순회: ";
    tree.Print(inOrder);
    std::cout << "후위 순회: ";
    tree.Print(PostOrder);


    if ( !tree.isExist(13) )
        std::cout << "없음\n";
    else
        std::cout << "있음\n";


    tree.Del(15);
    tree.Del(25);

    tree.Print(preOrder);


}