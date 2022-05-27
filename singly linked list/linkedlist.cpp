#include <iostream>
#include <iterator>
#include <map>
using namespace std;

struct node
{
    int val;
    node *next = NULL;
};

typedef struct node node;

int len(node *head)
{
    if (head->next == NULL)
    {
        return 0;
    }
    return 1 + len(head->next);
}

node *makeLL()
{
    node *head, *curr;
    int choice;
    head = new node;
    curr = head;
    cout << "\nAdd? : ";
    cin >> choice;
    if (choice)
    {
        cout << "\nEnter: ";
        cin >> head->val;
    }
    else
    {
        return head;
    }
    cout << "\nAdd? : ";
    cin >> choice;
    while (choice)
    {
        node *temp = new node;
        cout << "\nEnter: ";
        cin >> temp->val;
        curr->next = temp;
        curr = temp;
        cout << "\nAdd? : ";
        cin >> choice;
    }
    node *endNode = new node;
    curr->next = endNode;
    return head;
}

void displayLL(node *head)
{
    node *curr = head;
    cout << '\n';
    while (curr->next != NULL)
    {
        cout << curr->val << " | ";
        curr = curr->next;
    }
    cout << '\n';
}

node *removeLL(node *head, int key)
{
    if (head->val == key)
    {
        node *temp = head->next;
        free(head);
        return temp;
    }
    else
    {
        node *curr = head;
        while (curr->next != NULL)
        {
            if (curr->next->val == key)
            {
                node *temp = curr->next->next;
                free(curr->next);
                curr->next = temp;
            }
            curr = curr->next;
        }
        return head;
    }
}

node *popLL(node *head, int index)
{
    if (index + 1 <= len(head))
    {
        if (index == 0)
        {
            return removeLL(head, head->val);
        }
        node *curr = head;
        int curr_index = 0;
        while (curr_index + 1 != index)
        {
            curr = curr->next;
            curr_index++;
        }
        node *temp = curr->next->next;
        free(curr->next);
        curr->next = temp;
    }
    return head;
}

node *insertLL(node *head, int index, int key)
{
    if (len(head) == 0 && index == 0)
    {
        node *temp = new node, *end = new node;
        temp->val = key;
        temp->next = end;
        return temp;
    }
    if (index + 1 <= len(head))
    {
        if (index == 0)
        {
            node *newNOde = new node;
            newNOde->val = key;
            newNOde->next = head;
            return newNOde;
        }
        node *curr = head;
        int curr_index = 0;
        while (curr_index + 1 != index)
        {
            curr = curr->next;
            curr_index++;
        }
        node *newnode = new node, *temp = curr->next;
        newnode->val = key;
        curr->next = newnode;
        newnode->next = temp;
        return head;
    }
}

int getLL(node *head, int index)
{
    if (index + 1 <= len(head))
    {
        if (index == 0)
        {
            return head->val;
        }
        node *curr = head;
        int curr_index = 0;
        while (curr_index != index)
        {
            curr = curr->next;
            curr_index++;
        }
        return curr->val;
    }
}

bool searchLL(node *head, int key)
{
    node *curr = head;
    while (curr->next->next != NULL)
    {
        if (curr->val == key)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

node *setLL(node *head, int index, int key)
{
    if (index + 1 <= len(head))
    {
        if (index == 0)
        {
            head->val = key;
            return head;
        }
        node *curr = head;
        int curr_index = 0;
        while (curr_index != index)
        {
            curr = curr->next;
            curr_index++;
        }
        curr->val = key;
    }
    return head;
}

node *reverseLL(node *head)
{
    if (len(head) <= 1)
    {
        return head;
    }
    node *preEND = new node;
    preEND->val = head->val;
    node *endNode = new node;
    preEND->next = endNode;
    node *curr1 = head->next, *curr2 = preEND;
    while (curr1->next != NULL)
    {
        node *newNode = new node;
        newNode->val = curr1->val;
        newNode->next = curr2;
        curr2 = newNode;
        curr1 = curr1->next;
    }
    return curr2;
}


int main()
{
    node *head = makeLL();
    displayLL(head);
    node *l = insertLL(head, 0, 99);
    displayLL(l);
    l = reverseLL(l);
    displayLL(l);
}