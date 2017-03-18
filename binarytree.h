#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include "algorithms.h"

namespace algorithms {

namespace search {

    template<typename Item, typename Key>
    class BinaryTree
    {

    private:

        Key key;

        Item item;

        BinaryTree* parent;

        BinaryTree* left;

        BinaryTree* right;

        BinaryTree* searchR(BinaryTree* context, const Key& key)
        {
            if ((context == nullptr) || (key == context->getKey()))
            {
                return context;
            }

            if (key < context->getKey())
            {
                return this->searchR(context->getLeft(), key);
            }
            else
            {
                return this->searchR(context->getRight(), key);
            }
        }

    public:
        BinaryTree(const Key key, Item item)
        {
            this->key = key;
            this->item = item;
        }

        ~BinaryTree()
        {
            //std::cout << "Deleting tree node with key: " << this->getKey() << "..." << std::endl;

            if (this->left != nullptr)
            {
                delete this->left;
                this->left = nullptr;
            }

            if (this->right != nullptr)
            {
                delete this->right;
                this->right = nullptr;
            }
        }

        BinaryTree* getParent() const
        {
            return this->parent;
        }

        BinaryTree& setParent(BinaryTree* tree)
        {
            this->parent = tree;

            return *this;
        }

        BinaryTree* getLeft() const
        {
            return this->left;
        }

        BinaryTree& setLeft(BinaryTree* tree)
        {
            this->left = tree;

            return *this;
        }

        BinaryTree* getRight() const
        {
            return this->right;
        }

        BinaryTree& setRight(BinaryTree* tree)
        {
            this->right = tree;

            return *this;
        }

        Key getKey() const
        {
            return this->key;
        }

        BinaryTree& setKey(const Key& key)
        {
            this->key = key;

            return *this;
        }

        const Item& getItem() const
        {
            return this->item;
        }

        void insert(BinaryTree* tree)
        {
            BinaryTree* y = nullptr;
            BinaryTree* x = this;

            while (x != nullptr)
            {
                y = x;

                if (tree->getKey() < x->getKey())
                {
                    x = x->getLeft();
                }
                else
                {
                    x = x->getRight();
                }
            }

            tree->setParent(y);

            if (tree->getKey() < y->getKey())
            {
                y->setLeft(tree);
            }
            else
            {
                y->setRight(tree);
            }
        }

        BinaryTree* search(Key key)
        {
            return this->searchR(this, key);
        }

        BinaryTree* minimum()
        {
            BinaryTree* result = this;

            while (result->getLeft() != nullptr)
            {
                result = result->getLeft();
            }

            return result;
        }

        BinaryTree* maximum()
        {
            BinaryTree* result = this;

            while (result->getRight() != nullptr)
            {
                result = result->getRight();
            }

            return result;
        }

        static BinaryTree<Item, Key>* createTree(Key key, Item item)
        {
            return new BinaryTree<Item, Key>(key, item);
        }
    };

}

}

#endif // BINARYTREE

