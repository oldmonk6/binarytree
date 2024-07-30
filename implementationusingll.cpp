#include<iostream>
#include<queue>
#include <climits>
using namespace std;
class node{
    public:
    int val;
    node* right;
    node*left;
    node(int val)
    {
        this->val=val;
        this->right=NULL;
        this->left=NULL;

    }

};
class bt{
    public:
    node* root;
    bt()
    {
        this->root=NULL;
    }
    void insertright(int val)
    {
        node* temp=new node(val);
        if(root==NULL) root =temp;
        else{
            node*t=root;
            while(t->right!=NULL)
            {
                t=t->right;
            }
            t->right=temp;
        }
       
    }
    void insertleft(int val)
    {
        node* temp=new node(val);
        if(root==NULL) root =temp;
        else{
            node*t=root;
            while(t->left!=NULL)
            {
                t=t->left;
            }
            t->left=temp;
        }
       
    }
    void display(node* root)
    {
        node* head=root;
        if(head=NULL)return;
        cout<<head->val<<" ";
        display(head->left);
        display(head->right);
    }
    
};
int sum(node* root)
{
    if(root==NULL)return 0;
    
    return root->val+sum(root->left)+sum(root->right);


}
int size(node* root){
    
    if(root==NULL)return 0; 
    return 1+size(root->left)+size(root->right);

    
    
}
int maxval(node *root)
{
    if(root ==NULL)return INT_MIN;
    return max(max(root->val,maxval(root->left)),maxval(root->right));
    
}
int level(node* root)
{
    if(root==NULL )return 0;
    return 1+max(level(root->left),level(root->right));
}

int main()
{
    node* a=new node(1);
    node* b=new node(2);
    node* c=new node(3);
    node* d=new node(4);
    node* e=new node(5);
    node* f=new node(6);
    node* g=new node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    f->right=g;
   cout<< sum(a)<<endl;

   cout<<size(a)<<endl;
   cout<<maxval(a)<<endl;
   cout<<level(a)<<endl;






}