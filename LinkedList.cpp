#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Insert at end
    // Time Complexity: O(n)
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Search
    // Time Complexity: O(n)
    bool search(int value)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->data == value)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Delete
    // Time Complexity: O(n)
    void deleteNode(int value)
    {
        if(head == NULL)
        {
            return;
        }

        if(head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        while(current->next != NULL &&
              current->next->data != value)
        {
            current = current->next;
        }

        if(current->next != NULL)
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Linked List: ";
    list.display();

    cout << "Search 20: ";

    if(list.search(20))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    list.deleteNode(20);

    cout << "After Deletion: ";
    list.display();

    return 0;
}