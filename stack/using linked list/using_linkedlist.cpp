#include <iostream>
#include "linkedListUtil.h"


/*This implementation is inefficient. 
It has been improved in "using custom linked list" folder*/
using namespace std;

class myStack
{
    linkedList l;

public:
    myStack()
    {
        int a[0] = {};
        l = linkedList(a, 0);
    }


    void see()
    {
        l.see();
    }

    void push(int value)
    {
        l.insert(0, value);
    }

    void pop()
    {
        if(l.size() == 0)
        {
            cout << "\n***The stack is empty***\n";
            return;
        }
        l.pop();
    }

    int top()
    {
        return l.get(0);
    }

    bool empty()
    {
        if(l.size() == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
   myStack s = myStack();
   s.push(1);
   s.push(2);
   s.push(3);
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.push(3);
   s.push(2);
   s.push(1);
   cout << s.top();
   s.see();
}
