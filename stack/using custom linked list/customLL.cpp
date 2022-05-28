/* The idea here is to implement a linked list while maintaining a tail pointer
which always points to the last element if the list is non empty and is NULL 
otherwise*

-> Head pointer represents the top of our stack
-> Tail pointer represents the bottom.

1) PUSH method: insert at the tail  (O(1))
2) POP method: pop the head         (O(1))
3) FRONT method: return head->value (O(1))
*/

#include <iostream>
#include <iterator>
#include <map>
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

class llStack
{

    node *head;
    node *tail;
    int len;

public:
    llStack(int a[], int n)
    {
        if (n == 0)
        {
            this->head = new node();
            this->tail = NULL;
            this->len = n;
            return;
        }
        else
        {
            this->head = new node(a[0]);
            this->tail = head;
            node *curr = head;
            for (int i = 1; i < n; i++)
            {
                node *temp = new node(a[i]);
                curr->next = temp;
                curr = temp;
                tail = curr;
            }
            node *endNode = new node();
            curr->next = endNode;
            this->len = n;
            return;
        }
    }

    llStack() = default;

    void see()
    {
        if (this->len == 0)
        {
            return;
        }
        node *curr = head;
        cout << '\n';
        while (curr != tail)
        {
            cout << curr->val << "  "
                 << "tail: " << this->tail->val << '\n';
            curr = curr->next;
        }
        cout << curr->val << "  "
             << "tail: " << this->tail->val;
        cout << '\n';
    }

    void push(int value) // at the tail
    {
        if (this->len == 0)
        {
            node *temp = new node(value);
            temp->next = this->head;
            this->tail = temp;
            this->head = temp;
            this->len++;
            return;
        }
        else
        {
            node *newNode = new node(value), *temp = this->tail->next;
            this->tail->next = newNode;
            this->tail = newNode;
            newNode->next = temp;
            this->len++;
            return;
        }
    }

    void pop() // pop the head off
    {
        if (this->len != 0)
        {
            if (this->len == 1)
            {
                this->head = this->head->next;
                this->tail = NULL;
                free(head);
                this->len--;
                return;
            }
            else
            {
                node *temp = this->head->next;
                free(head);
                this->head = temp;
                this->len--;
                return;
            }
        }
        return;
    }

    int front()
    {
        if (this->len == 0)
        {
            cout << "\n****empty hai****";
            return -1;
        }
        return this->head->val;
    }

    bool empty()
    {
        if (this->len == 0)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return this->len;
    }
};

int main()
{
    int a[4] = {};
    llStack l = llStack(a, 0);
    l.push(1);
    l.push(2);
    l.push(3);
    l.see();
    l.pop();
    l.see();
    l.push(19);
    l.see();
    l.pop();
    l.see();
    cout << l.front();
}