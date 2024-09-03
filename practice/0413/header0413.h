#include<iostream>
using namespace std;
class Stack
{
public:
    int Stackarray[52];
    int Stackptr;
    int cardcounts;
    Stack();
    void Pop();
    void Push(int a);
    void Push();
    void Empty();
    void Top();
    void output();
    int checkarr(int* arr,int ptr,int number);
    int randomcard();
    void wash();
};
