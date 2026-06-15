#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:

    Node* insert(Node* root, int value)
    {
        if(root == NULL)
            return new Node(value);

        if(value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    bool search(Node* root, int value)
    {
        if(root == NULL)
            return false;

        if(root->data == value)
            return true;

        if(value < root->data)
            return search(root->left, value);

        return search(root->right, value);
    }

    void inorder(Node* root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

public:

    Node* root;

    BST()
    {
        root = NULL;
    }

    // Insert
    // Average Complexity: O(log n)
    void insert(int value)
    {
        root = insert(root, value);
    }

    // Search
    // Average Complexity: O(log n)
    bool search(int value)
    {
        return search(root, value);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    cout << "BST Inorder Traversal: ";
    tree.display();

    cout << "Search 40: ";

    if(tree.search(40))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}