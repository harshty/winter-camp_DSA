#include <iostream>

using namespace std;

struct ListNode
{
    char data;
    ListNode *next;
};

bool isInList(ListNode *head, char c)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        if (current->data == c)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main()
{
    ListNode *head = new ListNode{'a', nullptr};
    ListNode *tail = head;
    // add characters to the list
    for (int i = 1; i < 4; i++)
    {
        tail->next = new ListNode{(char)('a' + i), nullptr};
        tail = tail->next;
    }
    char c = 'c';

    if (isInList(head, c))
    {
        cout << c << " is in the list." << endl;
    }
    else
    {
        cout << c << " is not in the list." << endl;
    }
    return 0;
}