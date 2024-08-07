#pragma once

#include <cstring>

class ArrayList{
    private:
    unsigned mSize;

    unsigned mCapacity;

    int *mElement;   

    public:

    ArrayList();

    ArrayList(const ArrayList &other) = delete;

    ArrayList operator = (const ArrayList &other) = delete;

    ~ArrayList();

    int at(int index) const;
    void add(int element);
    void remove(int element);
    void removeAt(int index);
    bool contains(int element) const;
    unsigned size() const;

};

ArrayList :: ArrayList()
:mSize{0}, mCapacity{5}, mElement{nullptr}
{
    mElement = new int[mCapacity];
}

ArrayList :: ~ArrayList(){

    if (mElement != nullptr)
    {
        delete[] mElement;
        mElement = nullptr;
    }   
}

int ArrayList :: at(int index) const{
    
    if (index >= mSize)
    {
        return -1;
    }
    
    return mElement[index];
}

void ArrayList :: add(int element){

    if (mSize == mCapacity)
    {
        mCapacity *= 2;

        int *tempArray = new int[mCapacity];

        std::memcpy(tempArray, mElement, sizeof(int) * mSize);

        delete[] mElement;

        mElement = tempArray;
    }

    mElement[mSize] = element;
    ++mSize;
}

void ArrayList :: remove(int element){

    for (int i = 0; i < mSize; i++)
    {
        if (element == mElement[i])
        {
            std::memcpy(mElement + i, mElement + i + 1, sizeof(int) * (mSize - i - 1));
            --mSize;
            --i;
        }
    }
}

void ArrayList :: removeAt(int index){

   if (index >= mSize)
   {
        return ;
   }

    std::memcpy(mElement + index, mElement + index + 1, sizeof(int) * (mSize - index - 1));  
    --mSize;  
}

bool ArrayList :: contains(int element) const{

    for (int i = 0; i < mSize; i++)
    {
        if (element == mElement[i])
        {
            return true;
        }
    }

    return false;
}

unsigned ArrayList :: size() const{

    return mSize;
}