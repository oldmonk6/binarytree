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
    void preorderit(node* root)
    { //using stack
        stack<node*>st;
        st.push(root);
        
        while(st.size()>0)
        {
            node* temp=st.top();
            cout<<temp->val<<" ";
            st.pop();
            // putiing in reverse order because stack is lifo
            if(temp->right)st.push(temp->right);
          
            if(temp->left)st.push(temp->left);
            
           

        }
    }
    void postorderit(node* root)
    {// using 2 stacks
        stack<node*>st;
        vector<int>ans;
        st.push(root);
        
        while(st.size()>0)
        {
            node* temp=st.top();
            
            st.pop();
            ans.push_back(temp->val);
            
            if(temp->left)st.push(temp->left);
          
            if(temp->right)st.push(temp->right);
            
           

        }
        reverse(ans.begin(),ans.end());
       
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";

        }
    }
     void inorderit(node* root)
    { //using stack
        stack<node*>st;
    
        node* t=root;
        
        while(st.size()>0 || t!=NULL)
        {
           if(t)
           {
            st.push(t);
           t=t->left;
           }
           else{
            node* temp=st.top();
            st.pop();
            cout<<temp->val<<" ";
            t=temp->right;



           }
            
          
            
            
           

        }
    }
int main()
{
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    node* root=construct(arr,n);
    preorderit(root);
    cout<<endl;
    
    postorderit(root); 
    cout<<endl;
    inorderit(root); 
    




}