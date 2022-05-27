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

class linkedList
{
public:
    node *head;
    int len;
    int search_index; // don't bother
    linkedList(int a[], int n)
    {
        head = new Node;
        head->val = a[0];
        if (n == 0)
        {
            this->len = 0;
            return;
        }
        Node *curr = head;
        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node(a[i]);
            curr->next = temp;
            curr = temp;
        }
        node *endNode = new node;
        // endNode->next = NULL;
        curr->next = endNode;
        this->len = n;
    }

    void see()
    {
        node *curr = head;
        cout << '\n';
        while (curr->next != NULL)
        {
            cout << curr->val << " --> ";
            curr = curr->next;
        }
        cout << "endNode --> NULL";
        cout << '\n';
    }

    void push(int value)
    {
        if (this->size() == 0)
        {
            this->insert(0, 1);
            return;
        }
        this->len++;
        node *curr = this->head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        node *temp1 = curr->next;
        node *temp2 = new node(value);
        curr->next = temp2;
        temp2->next = temp1;
    }

    void insert(int index, int value)
    {
        if (this->len == 0 && index == 0)
        {
            this->len++;
            node *temp = new node(value), *end = new node;
            temp->next = end;
            this->head = temp;
            return;
        }
        if (index + 1 <= this->len)
        {
            this->len++;
            if (index == 0)
            {
                node *newNOde = new node(value);
                newNOde->next = this->head;
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

    int pop(int index = 0)
    {
        if (index + 1 <= this->len)
        {
            this->len--;
            if (index == 0)
            {
                int out = head->val;
                this->head = head->next;
                return out;
            }
            node *curr = head;
            int curr_index = 0;
            while (curr_index + 1 != index)
            {
                curr = curr->next;
                curr_index++;
            }
            node *temp = curr->next->next;
            int out = curr->next->val;
            free(curr->next);
            curr->next = temp;
            return out;
        }
    }

    void reverse()
    {
        if (this->len <= 1)
        {
            return;
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
        this->head = curr2;
        return;
    }

    void set(int index, int value)
    {
        if (index + 1 <= this->len)
        {
            if (index == 0)
            {
                head->val = value;
                return;
            }
            node *curr = head;
            int curr_index = 0;
            while (curr_index != index)
            {
                curr = curr->next;
                curr_index++;
            }
            curr->val = value;
            return;
        }
        return;
    }

    int get(int index)
    {
        if (index + 1 <= this->len)
        {
            if (index == 0)
            {
                return this->head->val;
            }
            node *curr = this->head;
            int curr_index = 0;
            while (curr_index != index)
            {
                curr = curr->next;
                curr_index++;
            }
            return curr->val;
        }
        return -1;
    }

    bool search(int value)
    {
        node *curr = this->head;
        int curr_index = 0;
        while (curr->next->next != NULL)
        {
            if (curr->val == value)
            {
                this->search_index = curr_index; // don't bother either
                return true;
            }
            curr = curr->next;
            curr_index++;
        }
        return false;
    }

    int index(int value)
    {
        bool is_in = this->search(value);
        return (is_in == true) ? this->search_index : -1;
    }

    void clear()
    {
        free(this->head);
        head = new node();
    }

    linkedList clone()
    {
        int a[1] = {this->head->val};
        linkedList out = linkedList(a, 1);
        node *curr = this->head->next;
        while (curr->next != NULL)
        {
            out.push(curr->val);
            curr = curr->next;
        }
        return out;
    }

    int size()
    {
        return this->len;
    }
};

int main()
{
    int a[0] = {};
    linkedList l = linkedList(a, 0);
    l.push(1);
    l.see();
}