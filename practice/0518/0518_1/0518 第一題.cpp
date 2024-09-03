#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int check(vector<string> v,string e)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==e)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ifstream vfriend;
    vfriend.open("Vincent.txt");
    ifstream lfriend;
    lfriend.open("Leo.txt");
    string temp;
    vector<string> vfriendlist;
    vector<string> lfriendlist;
    while(!vfriend.eof())
    {
        vfriend>>temp;
        if(!vfriend.fail())
        {
            vfriendlist.push_back(temp);
        }
    }
    while(!lfriend.eof())
    {
        lfriend>>temp;
        if(!lfriend.fail())
        {
            lfriendlist.push_back(temp);
        }
    }
    cout<<"Vincent's friends: ";
    for(int i=0;i<vfriendlist.size();i++)
    {
        cout<<vfriendlist[i]<<" / ";
    }
    cout<<endl;
    cout<<"Leo's friends: ";
    for(int i=0;i<vfriendlist.size();i++)
    {
        cout<<lfriendlist[i]<<" / ";
    }
    for(int i=lfriendlist.size()-1;i>=0;i--)
    {
        temp=lfriendlist[i];
        if(check(vfriendlist,temp)==0)
        {
            vfriendlist.push_back(temp);
        }
        lfriendlist.pop_back();
    }
    cout<<endl;
    cout<<"invitee: ";
    for(int i=0;i<vfriendlist.size();i++)
    {
        cout<<vfriendlist[i]<<" / ";
    }
    cout<<endl;
    ofstream theirfriends;
    theirfriends.open("invitee.txt");
    int counts=vfriendlist.size();
    while(counts)
    {
        temp=vfriendlist[vfriendlist.size()-1];
        theirfriends<<temp<<"\n";
        vfriendlist.pop_back();
        counts--;
    }
    theirfriends.close();
    vfriend.close();
    lfriend.close();

}
