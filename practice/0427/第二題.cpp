#include<iostream>
using namespace std;
class node
{
public:
    int number;
    int flag;
    node* ptr;
    node(int number)
    {
        this->number=number;
        this->flag=0;
        this->ptr=NULL;
    }
};
node* ini(int number)
{
    node* temp=new node(1);
    node* header=temp;
    for(int i=2;i<=number;i++)
    {
        temp->ptr=new node(i);
        temp=temp->ptr;
    }
    temp->ptr=header;
    return header;
}
int check(node* header,int number)
{
    node* temp=header;
    for(int i=1;i<=number;i++)
    {
        if(temp->number!=13)
        {
            if(temp->flag==0)
            {
                return 0;
            }
        }
        temp=temp->ptr;
    }
    return 1;
}
void setdefault(node* header,int number)
{
    node *temp=header;
    for(int i=0;i<number;i++)
    {
        temp->flag=0;
        temp=temp->ptr;
    }
}
int main()
{
    int number,flag=1;
    while(1)
    {
        cout<<"please enter the number: "<<endl;
        while(1)
        {
            cin>>number;
            if(number==0)
            {
                flag==0;
                break;
            }
            else if(number>=13&&number<100)
            {
                break;
            }
            else
            {
                cout<<"You should enter number 13<=number<100!"<<endl;
            }
        }
        if(flag==0)
        {
            break;
        }
        node *headptr=ini(number); //main process
        int test=0;
        for(int i=1;i<number;i++)
        {
            node* temp=headptr;
            while(1)
            {
                int j=i;
                temp->flag=1;
                while(j>0)
                {
                    temp=temp->ptr;
                    while(temp->flag==1)
                    {
                        temp=temp->ptr;
                    }
                    j--;
                }
                if(temp->number==13)
                {
                    if(check(headptr,number)==1)
                    {
                        cout<<"The answer is "<<i<<endl;
                        test=1;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(test==1)
            {
                break;
            }
            else
            {
                setdefault(headptr,number);
            }
        }
        if(test==0)
        {
            cout<<"No answer"<<endl;
        }
    }
}
