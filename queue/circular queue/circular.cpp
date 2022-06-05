#include <iostream>

using namespace std;

class queue
{
public:
    int *a;
    int start;
    int end;
    int len;
    int size;

    queue(int size = 0)
    {
        this->a = new int[size + 1];
        this->start = 0;
        this->end = 0;
        this->len = 0;
        this->size = size;
    }

    queue() = default;

    void push(int value)
    {
        int temp = this->end;
        temp++;
        temp = (temp) % (this->size + 1);
        if (temp == this->start)
        {
            cout << "\n***The queue is full***\n";
            return;
        }
        this->end = temp;
        a[end] = value;
        this->len++;
        return;
    }

    void pop()
    {
        if (this->end == this->start)
        {
            cout << "\n***The queue is empty***\n";
            return;
        }
        this->start = (this->start + 1) % (this->size + 1);
        this->len--;
        return;
    }

    void see()
    {
        if (this->end == this->start)
        {
            cout << "\n***The queue is empty***\n";
            return;
        }
        cout << '\n';
        int i = this->start;
        while(i != this->end)
        {
            i = (i + 1) % (this->size + 1);
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int front()
    {
        if(this->start == this->end)
        {
            cout << "\n***The queue is empty***\n";
            return -1;
        }
        int start_index = (this->start + 1) % (this->size + 1);
        return a[start_index];
    }
};

int main()
{
    queue q = queue(4);
    q.push(1);
    q.push(2);
    q.see();
    q.pop();
    q.pop();
    cout << q.front();
}