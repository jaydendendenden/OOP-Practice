#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};
class BinarySearchTree
{

public:
    TreeNode *header;
    BinarySearchTree();
    void findtoken(int x);
    void inordertraversal(TreeNode* header);
    void insertnode(TreeNode* node);
};
int main()
{
    BinarySearchTree atree;
    int testttt=0;
    while(1)
    {
        cout<<"press -1 end the program , press -2 to insert number , press -3 to show all tree ,or find the number you input: ";
        cin>>testttt;
        if(testttt==-1)
        {
            break;
        }
        else if(testttt==-2)
        {
            cout<<"input number you want to insert into tree: ";
            int a;
            cin>>a;
            TreeNode* newnode= new TreeNode(a);
            atree.insertnode(newnode);
        }
        else if(testttt==-3)
        {
            atree.inordertraversal(atree.header);
        }
        else if(testttt<-3)
        {
            cout<<"You should input positive number!";
            system("pause");
            system("cls");
        }
        else
        {
            atree.findtoken(testttt);
        }
    }
}
BinarySearchTree::BinarySearchTree()
{
    header = new TreeNode(-1);
    cout<<"Input numbers: ";
    int temp;
    while(cin>>temp)
    {
        TreeNode *ptr = new TreeNode(temp);
        if(header->val==-1)
        {
            header=ptr;
        }
        else
        {
            insertnode(ptr);
        }
        if(cin.get()=='\n')
        {
            break;
        }
    }
}
void BinarySearchTree::insertnode(TreeNode* node)
{
    TreeNode* temp=header;
    TreeNode* pre=header;
    int key=0; //0 right 1 left
    while(1)
    {
        if(temp==NULL)
        {
            if(key==1)
            {
                pre->left=node;
            }
            else
            {
                pre->right=node;
            }
            break;
        }
        else if(temp->val>=node->val)
        {
            pre=temp;
            temp=temp->left;
            key=1;
        }
        else
        {
            pre=temp;
            temp=temp->right;
            key=0;
        }
    }
}
void BinarySearchTree::inordertraversal(TreeNode* header)
{
    if(header == NULL)
    {
        return;
    }
    TreeNode* header2=this->header;
    inordertraversal(header->left);
    cout<<header->val<<" ";
    inordertraversal(header->right);
}
void BinarySearchTree::findtoken(int x)
{
    TreeNode* temp=header;
    while(temp)
    {
        if(temp->val>x)
        {
            temp=temp->left;
        }
        else if(temp->val<x)
        {
            temp=temp->right;
        }
        else
        {
            if(temp->left==NULL)
            {
                cout<<"Left:Null";
            }
            else
            {
                cout<<"Left:"<<temp->left->val;
            }
            if(temp->right==NULL)
            {
                cout<<" Right:Null";
            }
            else
            {
                cout<<" Right:"<<temp->right->val;
            }
            cout<<endl;
            break;
        }
    }
    if(temp==NULL)
    {
        cout<<"The value is not in this binary search tree."<<endl;
    }
}
