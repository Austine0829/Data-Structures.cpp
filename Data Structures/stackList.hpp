#include <string>

using std:: string, std:: cout;

#pragma once

class Stack{
    private:
    int top;
    int array[5];

    public:

    Stack(){

        top = -1;

        for (int i = 0; i < 5; i++)
        {
            array[i] = 0;
        }
    }

    bool isEmpty(){

        if (top == -1)
            return true;
        
        else
            return false;
    }

    bool isFull(){

        if (top == 4)
            return true;
        
        else
            return false;
    }

    void push(int value);
    int pop();
    int count();
    int peek(int index);
    void change(int index, int value);
    void display();
};

void Stack :: push(int value){

    if (isFull())
    {
        cout << "Stack Overflow\n";
    }

    else
    {
        top++;

        array[top] = value;
    }
}

int Stack :: pop(){

    if (isEmpty())
    {
        cout << "Stack Underflow\n";
        return -1;
    }

    else
    {
        int popValue = array[top];

        array[top] = 0;

        top--;

        return popValue;
    }
}

int Stack :: count(){

    return top + 1;
}

int Stack :: peek(int index){

    if (isEmpty())
    {
        cout << "Stack Underflow\n";
        return -1;
    }

    else
    {
        return array[index];
    }
}

void Stack :: change(int index, int value){

    array[index] = value;

    cout << "Value Has Been Change In Index: " << index << "\n";
}

void Stack :: display(){

    cout << "Stack Values\n";

    for (int i = count(); i >= 0; i--)
    {
        if (array[i] != 0)
        {
             cout << array[i] << "\n";
        }   
    }
}