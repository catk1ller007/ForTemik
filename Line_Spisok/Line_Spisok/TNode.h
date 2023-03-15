#pragma once
class TNode {

    int info;
    TNode* next;

public:
    TNode(int _info = 0);
    TNode(const TNode& tmp);
    ~TNode();

    TNode& operator=(TNode tmp);
    int getInfo();
    void setInfo(int k);
    TNode* getNext();
    TNode* setNext(TNode* tmp);
};