#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "binarytree.h"

using namespace std;

using algorithms::search::BinaryTree;

template<typename Item, typename Key>
void walkTree(std::ostream& stream, const BinaryTree<Item, Key>* tree)
{
    if (tree != nullptr)
    {
        walkTree(stream, tree->getLeft());
        stream << "key: " << tree->getKey() << " value: " << tree->getItem() << std::endl;
        walkTree(stream, tree->getRight());
    }
}

int main()
{
    int rootKey = 55;
    float rootItem = 3.14;

    BinaryTree<float, int>* root = BinaryTree<float, int>::createTree(rootKey, rootItem);

    const int maxTreeNodes = 50;
    const int min = 0;
    const int max = 500;

    srand(time(nullptr));
    for (int i = 0; i < maxTreeNodes; i++)
    {
        float item = (float)rand() / (float) RAND_MAX;
        int key  = min + (rand() % (int)(max - min + 1));

        root->insert(BinaryTree<float, int>::createTree(key, item));
    }

    walkTree(std::cout, root);

    const BinaryTree<float, int>* minNode = root->minimum();
    cout << "Minimum key: " << minNode->getKey() << " value: " << minNode->getItem() << endl;

    const BinaryTree<float, int>* maxNode = root->maximum();
    cout << "Maximum key: " << maxNode->getKey() << " value: " << maxNode->getItem() << endl;

    int randKey  = min + (rand() % (int)(max - min + 1));
    cout << "Searching item with key = " << randKey << "..." << endl;

    BinaryTree<float, int>* searchItem = root->search(randKey);
    if (searchItem != nullptr)
    {
        cout << "This value is: " << searchItem->getItem() << endl;
    }
    else
    {
        cout << "Item does not exist!" << endl;
    }

    delete root;

    return 0;
}

