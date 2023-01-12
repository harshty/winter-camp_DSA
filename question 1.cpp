#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void addValueAtPosition(int data, int position)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *current = head;
        for (int i = 0; i < position - 1; i++)
        {
            if (current->next == nullptr)
            {
                break;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteValueAtPosition(int position)
    {
        if (head == nullptr)
        {
            return;
        }

        if (position == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        for (int i = 0; i < position - 1; i++)
        {
            if (current->next == nullptr)
            {
                break;
            }
            current = current->next;
        }

        if (current->next == nullptr)
        {
            return;
        }

        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
};

int main()
{
    LinkedList list;
    list.addValueAtPosition(1, 0);
    list.addValueAtPosition(2, 1);
    list.addValueAtPosition(3, 2);
    list.addValueAtPosition(4, 3);
    list.addValueAtPosition(5, 4);
    list.printList(); // prints 1 2 3 4 5
    list.deleteValueAtPosition(2);
    list.printList(); // prints 1 2 4 5
    return 0;
}