/*
todo: Given 'n', print first n binary numbers in linear time.
* Idea: Inintialize a queue q with '1' in it.
* DO this n times:
    * take out the top element, print it.
    * q.push(q.top.append('0'))
    * q.push(q.top.append('1'))
*/

#include <bits/stdc++.h>

using namespace std;

void binaryNumbers(int n)
{   // printing first n binary numbers.
    if (n == 0)
    {
        return;
    }
    queue<string>q;
    string s = "1";
    q.push(s);
    int count = 0;
    while (count != n)
    {
        string temp = q.front();
        q.pop();
        cout << temp << '\n';
        count++;
        string a = temp, b = temp;
        a.push_back('0');
        b.push_back('1');
        q.push(a);
        q.push(b);
    }
}

int main()
{
    binaryNumbers(20);
}

