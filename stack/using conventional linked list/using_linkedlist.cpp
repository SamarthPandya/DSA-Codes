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
        l.push(value);
    }

    void pop()
    {
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
   return 0;
}
