#include<iostream>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int val;
    node* next = NULL;
    node* prev = NULL;
    node(int value)
    {
        this->val = value;
    }
    node() = default;
};

class Dll{
public:
    node*head;
    node*tail;
    int size = 0;
    
    void push(node* keyNode)
    {
        if(this->size == 0)
        {
            this->head = keyNode;
            this->tail = this->head;
            this->head->prev = NULL;
            this->tail->next = NULL;
        }
        else
        {
            this->tail->next = keyNode;
            keyNode->prev = this->tail;
            this->tail = keyNode;
        }
        this->size++;
    }

    void remove(node*keyNode)
    {
        if(this->size == 0)
        {
            cout << "\nNothing to remove\n";
            return;
        }
        if(keyNode == this->head)
        {
            if(this->size == 1)
            {
                this->head = NULL;
                this->tail = this->head;
                free(keyNode);
            }
            else
            {
                node* newHead = this->head->next;
                free(this->head);
                newHead->prev = NULL;
                this->head = newHead;
            }
        }
        else
        {
            keyNode->prev->next = keyNode->next;
            keyNode->next->prev = keyNode->prev;
            free(keyNode);
        }
        this->size--;
    }

    void see()
    {
        if(this->size == 0)
        {
            cout << "\nEmpty\n";
            return;
        }
        node*temp = this->head;
        cout << '\n';
        while(temp->next)
        {
            cout << temp->val << " << ";
            temp = temp->next;
        }
        cout << temp->val;
        cout << '\n';
    }
};

class Lru
{
public:
    Dll d;
    unordered_map<int, node*>m;
    int cap;

    Lru(int capacity)
    {
        this->cap = capacity;
    }

    void push(int value)
    {
        auto it = m.find(value);
        if(it != m.end())
        {
            return;
        }
        node* newElement = new node(value);
        if(d.size == this->cap)
        {
            cout << "L.R.U = " << this->d.head->val << '\n';
            int temp = this->d.head->val;
            this->d.remove(d.head);
            this->m.erase(temp);
            this->d.push(newElement);
            this->m.insert({value, newElement});
        }
        else
        {
            d.push(newElement);
            m.insert({ value, newElement });
        }
    }

    int find(int value)
    {
        auto it = m.find(value);
        if(it == m.end())
        {
            return -1;
        }
        else
        {
            node* latest = (*it).second;
            d.remove(latest);
            node* temp = new node(value);
            d.push(temp);
            cout << "\nM.R.U = " << this->d.tail->val << '\n';
            return (*it).first;
        }
    }

    void see()
    {
        this->d.see();
    }
};

int main()
{
    Lru l = Lru(1);
    l.push(1);
    l.push(12);
    l.push(14);
    l.see();
}