#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    int arr[9] = {7,5,15,1,6,9,2,3,4};
    BinaryTree* bt = new BinaryTree(arr,9);
    cout<<"In-Order:"<<endl;
    bt->inOrderPrint(bt->getRoot());
    cout<<"Post-Order:"<<endl;
    bt->postOrderPrint(bt->getRoot());

    cout<<"Deleting 5"<<endl;
    bt->deleteNode(bt->getRoot(), 5);
    cout<<"In-Order:"<<endl;
    bt->inOrderPrint(bt->getRoot());
    cout<<"Post-Order:"<<endl;
    bt->postOrderPrint(bt->getRoot());

    BinaryTree* bt2 = new BinaryTree(arr,9);
    cout<<"In-Order:"<<endl;
    bt2->inOrderPrint(bt2->getRoot());
    cout<<"Post-Order:"<<endl;
    bt2->postOrderPrint(bt2->getRoot());

    cout<<"Deleting 5"<<endl;
    bt2->deleteAndReplaceMinRight(bt2->getRoot(), 5);

    cout<<"In-Order:"<<endl;
    bt2->inOrderPrint(bt2->getRoot());
    cout<<"Post-Order:"<<endl;
    bt2->postOrderPrint(bt2->getRoot());
    return 0;
}
