#include<iostream>
using namespace std;
class matrix
{
public:
    static int n;
    int arr1[16]={0};
    static void add(matrix* a, matrix* b);
    static void sub(matrix* a, matrix* b);
    static void multiple(matrix* a, matrix* b);
    static void divide(matrix* a, matrix* b);
    void input(matrix* a, matrix* b);
};
