#include<iostream>
#include <climits>
#include<queue>
#include<stack>
#include<algorithm>
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
node* construct(int arr[],int n)
{
    queue<node*> q;
    node* root=new node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n)
    {
        node* temp=q.front();
        q.pop();
        node* l;
        node* r;
        if(arr[i]!=INT_MIN)l=new node(arr[i]);
        else l=NULL;
        if( j!=n && arr[j]!=INT_MIN)r=new node(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l!=NULL)q.push(l);
        if(r!=NULL)q.push(r);
        i+=2;
        j+=2;


    }
    return root;

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
    void leftboundary(node* root)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)return;
        cout<<root->val<<" ";
        leftboundary(root->left);
        if(root->left==NULL)leftboundary(root->right);
    }
    void bottomboundary(node* root)
    {
        
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)
        {
            cout<<root->val<<" ";
            return;
        }
        
        bottomboundary(root->left);
        bottomboundary(root->right);

    }
    void rightboundary(node* root)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)return;
        
        rightboundary(root->right);
        if(root->right==NULL)rightboundary(root->left);
        cout<<root->val<<" ";
    }

    
int main()
{
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n=sizeof(arr)/sizeof(arr[0]);
    node* root=construct(arr,n);
    //levelorder(root);
   // boundary(root);
   leftboundary(root);
   cout<<endl;
   bottomboundary(root);
   cout<<endl;
   rightboundary(root->right);
    




}