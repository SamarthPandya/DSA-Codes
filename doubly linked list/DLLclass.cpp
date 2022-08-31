#include <iostream>
#include <iterator>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;
    Node *prev = NULL;

    Node(int value)
    {
        this->val = value;
    }
    Node() = default;
};

typedef Node node;

class Dll
{
public:
    node *head;
    int len;
    Dll(int a[], int n)
    {
        head = new Node;
        head->val = a[0];
        Node *curr = head;
        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node(a[i]);
            curr->next = temp;
            temp->prev = curr;
            curr = temp;
        }
        node *endNode = new node;
        // endNode->next = NULL;
        curr->next = endNode;
        endNode->prev = curr;
        this->len = n;
    }

    Dll() = default;

    void see()
    {
        node *curr = head;
        cout << '\n';
        while (curr->next != NULL)
        {
            cout << curr->val << "  <-->  ";
            curr = curr->next;
        }
        cout << "endNode --> NULL";
        cout << '\n';
    }
};

int main()
{
    
}