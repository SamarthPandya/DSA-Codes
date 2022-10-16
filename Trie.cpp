#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class node{
    public:
    node*links[26] = {NULL};
    bool status;
};

class Trie{
    public:
    node* root;
    Trie()
    {
        root = new node();
    }
    void insert(string s)
    {
        if(!s.size())
        {
            return;
        }
        node*curr = this->root;
        int i = 0;
        while(i < s.size() - 1)
        {
            if(curr->links[s[i] - 'a'])
            {
                cout << s[i] << " present\n";
                curr = curr->links[s[i] - 'a'];
            }
            else
            {
                cout << s[i] << " Not present, adding.\n";
                node* temp = new node();
                curr->links[s[i] - 'a'] = temp;
                curr = curr->links[s[i] - 'a'];
            }
            i++;
        }
        if(curr->links[s[i] - 'a'])
        {
            cout << s[i] << " present\n";
            curr->links[s[i] - 'a']->status = true;
        }
        else
        {
            cout << s[i] << " Not present, adding.\n";
            node* temp = new node();
            temp->status = true;
            curr->links[s[i] - 'a'] = temp;
        }
    }

    bool exists(string s)
    {
        int i = 0;
        node*curr = this->root;
        while(i < s.size())
        {
            if(!curr->links[s[i] - 'a'])
            {
                return false;
            }
            else
            {
                curr = curr->links[s[i] - 'a'];
            }
            i++;
        }
        if(curr->status == true)
        {
            return true;
        }
        return false;
    }
    bool startsWith(string s)
    {
        int i = 0;
        node*curr = this->root;
        while(i < s.size() - 1)
        {
            if(!curr->links[s[i] - 'a'])
            {
                return false;
            }
            curr = curr->links[s[i] - 'a'];
            i++;
            
        }
        return true;
    }
};

int main()
{
    Trie t = Trie();
    string b = "apple", c = "app";
    t.insert(b);
    cout << t.exists(b) << '\n';
    cout << t.exists(c) << '\n';
    cout << t.exists(b) << '\n';
    cout << t.startsWith(c) << '\n';
    t.insert(c);
    cout << t.exists(c);
}