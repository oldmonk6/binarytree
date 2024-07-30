#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
    int val;
    node* right;
    node* left;
    node(int val)
    {
        this->val=val;
        this->right=NULL;
        this->left=NULL;
    }
};
class tree
{
    public:
    node *root;
    tree()
    {
        this->root=NULL;
    }
   
    void traversalinor(node* root,stack<int> &st)
    {
        node* temp=root;
        stack<int>st;
        if(temp->left==NULL || temp->right==NULL){
            st.push(temp->val);
            cout<<st.top();
            st.pop();
            return ;
        }
        traversalinor(temp->left,st);
        st.push(temp->val);
        cout<<st.top();
        st.pop();
        traversalinor(temp->right,st);


    }
    void traversalpreor(node* root)
    {
        node* temp=root;
        if(temp->left==NULL || temp->right==NULL){
            cout<<temp->val;
            return ;
        }
        cout<<temp->val;
        traversalpreor(temp->left);
        traversalpreor(temp->right);


    }
    void traversalinor(node* root)
    {
        node* temp=root;
        stack< node*>st;
        st.push(temp);
       
        while(st.size()>0)
        {
            while(temp->left!=NULL)
            {
                st.push(temp->left);
                temp=temp->left;
            }
            temp=st.top();
            cout<<temp->val;
            st.pop();
            if(temp->right){
                temp=temp->right;
            }
        }
    }
    


};
int main()
{

}