#include <iostream>

using std:: cout;

#pragma once

class Queue{
    private:
    int front;
    int rear;
    int array[5];

    public:
    Queue(){
        
        front = -1;
        rear = -1;

        for (int i = 0; i < 5; i++)
        {
            array[i] = 0;
        }
        
    }

    bool isEmpty(){

        if (rear == -1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isFull(){

        if (rear == 4)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void enqueue(int value);
    int dequeue();
    int count();
    void display();
};

void Queue :: enqueue(int value){

    if (isFull())
    {
        cout << "Queue Is Full\n";
    }

    else
    {
        rear++;

        array[rear] = value;

    }
}

int Queue :: dequeue(){

    if (isEmpty())
    {
        cout << "Queue Is Empty\n";
        return -1;
    }

    else
    {   
        front++;
        
        int x = array[rear];
        array[front] = 0;

        rear--;

        return x;
    }
}

int Queue :: count(){

    return (rear + 1);
}

void Queue :: display(){

    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }  
}