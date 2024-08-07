#pragma once

class ListNode{
    private:
    int mValue;

    ListNode *mNextNode;

    public:

    ListNode(int value);

    ListNode(const ListNode &other) = delete;

    ListNode operator = (const ListNode &other) = delete;

    ~ListNode();

    int value() const;

    ListNode *nextNode() const;

    void setNextNode(ListNode *nextNode);
};

ListNode :: ListNode(int value)
:mValue{value}, mNextNode{nullptr}
{

}

ListNode:: ~ListNode(){

    if (mNextNode != nullptr)
    {
        delete mNextNode;
        mNextNode = nullptr;
    }
}

int ListNode :: value() const{

    return mValue;
}

ListNode *ListNode :: nextNode() const{

    return mNextNode;
}

void ListNode :: setNextNode(ListNode *nextNode){

    mNextNode = nextNode;
}

class LinkedList{
    private:
    ListNode *mHead;

    ListNode *mCurrent;

    int mSize;
    public:

    LinkedList();

    LinkedList(const LinkedList &other) = delete;

    LinkedList operator = (const LinkedList &other) = delete;

    ~LinkedList();

    int at(int index) const;
    void add(int element);
    void remove(int element);
    int removeAt(int index);
    bool contains(int element);
    unsigned size() const;
};

LinkedList :: LinkedList()
:mHead{new ListNode(0)}, mSize{0}
{
    mCurrent = mHead;
}

LinkedList :: ~LinkedList(){

    if (mHead != nullptr)
    {
        delete mHead;
        mHead = nullptr;
    }
}

int LinkedList :: at(int index) const{

    if (index >= mSize)
    {
        return -1;
    }

    int i = 0;

    ListNode *node = mHead->nextNode();

    while (node != nullptr && i < index)
    {
        node = node->nextNode();
        ++i;
    }

    if (node != nullptr)
    {
        return node->value();
    }

    return -1;
}

void LinkedList :: add(int element){

    ListNode *newNode = new ListNode(element);

    mCurrent->setNextNode(newNode);

    mCurrent = newNode;

    ++mSize;
}

void LinkedList :: remove (int element){

    ListNode *node = mHead->nextNode();
    ListNode *prev = mHead;

    while (node != nullptr && element != node->value())
    {
        prev = node;
        node = node->nextNode();
    }

    if (node != nullptr)
    {
        prev->setNextNode(node->nextNode());
        node->setNextNode(nullptr);
        
        delete node;
    }

    --mSize;
}

int LinkedList :: removeAt(int index){

    if (index >= mSize)
    {
        return -1;
    }

    int i = 0;

    ListNode *node = mHead->nextNode();
    ListNode *prev = mHead;
 
    while (node != nullptr && i < index)
    {
        prev = node;
        node = node->nextNode();

        ++i;
    }

    if (node != nullptr)
    {
        prev->setNextNode(node->nextNode());
        node->setNextNode(nullptr);
        
        delete node;
    }

    --mSize;

    return -1; 
}

bool LinkedList :: contains(int element){

    ListNode *node = mHead->nextNode();

    while (node != nullptr)
    {
        if (element == node->value())
        {
            return true;
        }
    
        node = node->nextNode();
    }

    return false;
}

unsigned LinkedList :: size() const{

    return mSize;
}