/*
Q2. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().
*/

#include <iostream>
#define SIZE 5

using namespace std;

class Stack
{
    int i = 0;
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[this->size];
    }
    void push(int value)
    {
        top++;
        arr[top] = value;
    }

    int pop()
    {
        return arr[top]--;
    }

    int peek()
    {
        return arr[top];
    }

    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void print()
    {
        for (i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    ~Stack()
    {
        delete[] arr;
        arr = NULL;
    }
};
enum Emenu
{
    EXIT,
    PUSH,
    POP,
    PEEK,
    IS_EMPTY,
    IS_FULL,
    DISPLAY_STCK_ELEMENTS
};
int main()
{
    int choice, num, size, n;
    cout << "\nDo you want to enter stack size [1] for Yes , [0] for No : ";
    cin >> n;
    if (n != 0)
    {
        cout << "\nEnter stack size : ";
        cin >> size;
    }
    else
        size = 5;

    Stack s(size);
    do
    {
        cout << "\n0.Exit.";
        cout << "\n1.Push.";
        cout << "\n2.Pop.";
        cout << "\n3.Peek.";
        cout << "\n4.Is stack Empty.";
        cout << "\n5.Is stack Full.";
        cout << "\n6.Display Stack.";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch (Emenu(choice))
        {
        case PUSH:
            if (s.isFull() != 1)
            {
                cout << "Enter number to push in stack : ";
                cin >> num;
                s.push(num);
            }
            else
            {
                cout << "\nStack is full!";
            }
            break;
        case POP:
            if (s.isEmpty() == 1)
            {
                cout << "\nStack is empty!!";
            }
            else
            {
                s.pop();
            }
            break;
        case PEEK:
            if (s.isEmpty() == 1)
            {
                cout << "\nStack is empty!!";
            }
            else
            {
                cout << "\nTop element in the stack is : " << s.peek();
            }
            break;
        case IS_EMPTY:
            if (s.isEmpty() == 1)
            {
                cout << "\nStack is empty.";
            }
            else
            {
                cout << "\nStack is not empty.";
            }
            break;
        case IS_FULL:
            if (s.isFull() == 1)
            {
                cout << "\nStack is full.";
            }
            else
            {
                cout << "\nStack is not full";
            }
            break;
        case DISPLAY_STCK_ELEMENTS:
            if (s.isEmpty() == 1)
            {
                cout << "\nStack is empty.";
            }
            else
            {
                s.print();
            }
            break;
        default:
            cout << "You have entered wrong choice!!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}