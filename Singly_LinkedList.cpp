#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void LLTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " --> ";
        ptr = ptr->next;
    }
}

struct node *InsertAtBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct node *InsertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct node *InsertAtPos(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node *InsertAfterNode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    struct node *head, *second, *third, *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 11;
    head->next = second;

    second->data = 16;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 29;
    fourth->next = NULL;

    cout << "Linked List before insertation" << endl;
    LLTraversal(head);
    cout << endl;

    cout << "Linked List after insertation" << endl;
    head = InsertAfterNode(head, third, 77);
    LLTraversal(head);

    return 0;
}