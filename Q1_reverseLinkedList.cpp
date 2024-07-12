// Q1 Write a function to reverse a singly linked list.The function should take the head of the list and return the new head of the reversed list.

#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node(int v)
    {
        val = v;
        next = NULL;
    }
};

node *reverse(node *head)
{
    node *prev = head;
    node *curr = head->next;
    while (curr != NULL)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = NULL;
    head = prev;
    return head;
}

int main()
{
    // Created a dummy linkedlist
    node *head = new node(1);
    node *temp = head;
    for (int i = 2; i <= 5; i++)
    {
        temp->next = new node(i);
        temp = temp->next;
    }
    temp->next = NULL;
    
    temp = head;
    cout << "Before reverse" << endl;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }

    node *reversedHead = reverse(head);

    temp = reversedHead;
    cout << "After reverse" << endl;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }

    return 0;
}
