#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;

    Node(int value)
    {
        this->val = value;
    }
    Node() = default;
};

typedef Node node;

class cirLinkedList
{
public:
    node *head;
    int len;

    cirLinkedList(int a[], int n)
    {
        if (n == 0)
        {
            node *temp = new node();
            temp->next = temp;
            this->head = temp;
            this->len = 0;
            return;
        }
        else
        {
            this->head = new node(a[0]);
            node *curr = this->head;
            for (int i = 1; i < n; i++)
            {
                node *temp = new node(a[i]);
                curr->next = temp;
                curr = temp;
            }
            curr->next = this->head;
            this->len = n;
            return;
        }
    }

    cirLinkedList() = default;

    void see()
    {
        if (this->len == 0)
        {
            return;
        }
        node *curr = this->head;
        while (curr->next != this->head)
        {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << curr->val << ' ';
        return;
    }

    void append(int value)
    {
        if (this->len == 0)
        {
            this->head->val = value;
            this->len++;
            return;
        }
        this->len++;
        node *curr = this->head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        node *temp2 = new node(value);
        curr->next = temp2;
        temp2->next = this->head;
    }

    void insert(int index, int value)
    {
        if (this->len == 0 && index == 0)
        {
            this->append(value);
        }
        if (index + 1 <= this->len)
        {
            this->len++;
            if (index == 0)
            {
                node *end = this->head->next;
                while(end->next != this->head)
                {
                    end = end->next;
                }
                node *newNOde = new node(value);
                newNOde->next = this->head;
                end->next = newNOde;
                this->head = newNOde;
                return;
            }
            node *curr = head;
            int curr_index = 0;
            while (curr_index + 1 != index)
            {
                curr = curr->next;
                curr_index++;
            }
            node *newnode = new node(value), *temp = curr->next;
            curr->next = newnode;
            newnode->next = temp;
            return;
        }
    }
};

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    cirLinkedList l = cirLinkedList(a, 5);
    l.append(323);
    l.append(99);
    l.insert(6, 88);
    l.see();
}