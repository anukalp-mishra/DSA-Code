#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void DLL_Traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != NULL);
}

struct node *InsertAtBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    return ptr;
}

int main()
{
    struct node *n1, *n2, *n3, *n4;
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));
    n4 = (struct node *)malloc(sizeof(struct node));

    n1->data = 3;
    n1->next = n2;
    n1->prev = NULL;

    n2->data = 5;
    n2->next = n3;
    n2->prev = n1;

    n3->data = 7;
    n3->next = n4;
    n3->prev = n2;

    n4->data = 9;
    n4->next = NULL;
    n4->prev = n3;

    cout << "Doubly Linked List before insertation" << endl;
    DLL_Traversal(n1);

    cout << endl;

    cout << "Doubly Linked List after insertation" << endl;
    n1 = InsertAtBeg(n1, 77);
    DLL_Traversal(n1);

    return 0;
}