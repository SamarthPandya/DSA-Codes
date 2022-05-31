#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class myStack
{
public:
    vector<int> a;

    myStack() = default;

    void push(int value)
    {
        this->a.push_back(value);
    }

    void pop()
    {
        a.erase(a.begin() + a.size() - 1);
    }

    int top()
    {
        return a[a.size() - 1];
    }

    bool empty()
    {
        return (a.size() == 0) ? true : false;
    }

    void see()
    {
        cout << '\n';
        for (auto i = a.rbegin(); i!= a.rend(); i++)
        {
            cout << *i << ' ';
        }
        cout << '\n';
    }
};

int main()
{
}