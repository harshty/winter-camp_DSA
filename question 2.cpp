#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node *addTwoLists(Node *first, Node *second)
{
    Node *res = NULL;
    Node *temp = NULL;
    Node *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new Node;
        temp->data = sum;

        if (res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (carry > 0)
    {
        temp->next = new Node;
        temp->next->data = carry;
    }

    return res;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *first = NULL;
    Node *second = NULL;
    Node *res = NULL;

    push(&first, 5);
    push(&first, 1);
    push(&first, 7);

    push(&second, 2);
    push(&second, 9);
    push(&second, 5);

    res = addTwoLists(first, second);
    cout << "Resultant list is ";
    printList(res);

    return 0;
}