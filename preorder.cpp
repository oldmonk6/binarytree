#include<iostream>
#include <climits>
#include<queue>
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
void display(node* root)
    { //preorder
       
        if(root==NULL)return;
        cout<<root->val<<" ";
        display(root->left);
        display(root->right);
    }
void display2(node* root)
{//inorder
   
     if(root==NULL){
         
          return ;
     }
    
     display2(root->left);
    cout<<root->val<<" ";
     display2(root->right);
      
}
void display3(node * root)
{//postorder
    if(root==NULL){
         
          return ;
     }
    
     display3(root->left);
    
     display3(root->right);
     cout<<root->val<<" ";

}
void disnlvl(node * root,int level,int curl)
{
    if(root==NULL)return ;
    if(level==curl){
        cout<<root->val<<" ";
        return;
    }
    disnlvl(root->left,level+1,curl);
    disnlvl(root->right,level+1,curl);
    

}
int level(node* root)
{
    if(root==NULL )return 0;
    return 1+max(level(root->left),level(root->right));
}
void levelorder(node* root)
{
    int n=level(root);
    for(int i=1;i<=n;i++)
    {
        disnlvl(root,1,i);
        cout<<endl;

    }
}
void levelorderqueue(node* root)
    {
        queue<node*> q;
        q.push(root);
        while(q.size()>0)
        {
            node* temp=q.front();
            q.pop();
            cout<<temp->val;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);

        }
        cout<<endl;

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
    disnlvl(a,1,3);
    cout<<endl;
   



}