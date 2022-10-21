#include<iostream>
#include<queue>
using namespace std;
struct node{
    node*left;
    node*right;
    int data;
    node(int data=0)
    {
        this->data=data;
        this->left=this->right=nullptr;
    }
};
class BST{
    node*root;
public:
    BST()
    {
        this->root=nullptr;
    }
    bool insert(int data)
    {
        return insert_(root,data);
    }
    bool insert_(node*&root,int data)
    {
        if(root==NULL)
        {
            node*n_node=new node(data);
            root=n_node;
            return true;
        }
        if(root->data==data)
            return false;
        if(data<root->data)
            return insert_(root->left,data);
        if(data>root->data)
            return insert_(root->right,data);
        return true;
    }
    void print()
    {
        print_(root);
    }
    void print_(node*root)
    {
        if(root==NULL)
            return;
        print_(root->left);
        cout<<root->data<<" ";
        print_(root->right);
    }
    void delete_node(node*&root,int data)
    {
        if(root==NULL)
            return;
        if(root->data==data)
        {
            if(root->left==NULL && root->right==NULL)
            {
                node*t=root;
                root=NULL;
                delete t;
                return;
            }
            if(root->left==NULL)
            {
                node*t=root;
                root=root->right;
                delete t;
                return;
            }
            if(root->right==NULL) {
                node *t = root;
                root = root->left;
                delete t;
                return;
            }
        }
        if(data>root->data)
            delete_node(root->right,data);
        else
            delete_node(root->left,data);
    }
    void del_n(int key)
    {
        delete_node(root,key);
    }

    void get_max(node*root,queue<int>&q)
    {
        if(root==NULL)
            return;
        q.push(root->data);
        get_max(root->left,q);
        get_max(root->right,q);
    }
   int get_max_k(int k)
   {
        queue<int>q;
        get_max(root,q);
        for(int i=0;i<=q.size()-k;q.pop(),i++);
        return q.front();
   }
   int get_min_k(int k)
   {
        queue<int>q;
        get_max(root,q);
        for(int i=0;i<k-1;i++,q.pop());
        return q.front();
   }
   int height_(node*root) {
       if (root == NULL)
           return 0;
       return (1+max(height_(root->right),height_(root->left)));
   }
   int get_height()
   {
        return height_(root);
   }
   int len(node*root)
   {
        if(root==NULL)
            return 0;
        else
            return (1+len(root->left)+len(root->right));
   }
   int get_length()
   {
        return len(root);
   }
    void print1_(node*root)
    {
        if(root==NULL)
            return;
        cout<<root->data<<" ";
        print_(root->left);
        print_(root->right);
    }
   void level_order_traversal()
   {
       print1_(root);
   }
};
int main()
{
    BST*ptr0=new BST();
    ptr0->insert(20);
    ptr0->insert(10);
    ptr0->insert(30);
    ptr0->insert(50);
    ptr0->insert(15);
    ptr0->insert(11);
    ptr0->print();
    cout<<endl;
    ptr0->del_n(10);
    cout<<"After 10 is deleted tree is:-\n";
    ptr0->print();
    cout<<endl;
    BST*ptr=new BST();
    ptr->insert(1);
    ptr->insert(2);
    ptr->insert(3);
    ptr->insert(4);
    ptr->insert(5);
    ptr->insert(6);
    ptr->insert(7);
    ptr->insert(8);
    ptr->insert(9);
    ptr->insert(10);
    cout<<"Level-Order Traversal is:-\n";
    ptr->level_order_traversal();
    cout<<endl;
    cout<<"7th max is:-"<<ptr->get_max_k(7)<<endl;
    cout<<"7th min k is:-"<<ptr->get_min_k(7)<<endl;
    BST*ptr1=new BST();
    ptr1->insert(10);
    ptr1->insert(20);
    ptr1->insert(30);
    ptr1->insert(40);
    ptr1->insert(28);
    ptr1->insert(27);
    ptr1->insert(50);
    ptr1->insert(29);
    cout<<"Level Order Traversal is:-\n";
    ptr1->level_order_traversal();
    cout<<endl;
    cout<<"height of tree is:-"<<ptr1->get_height()-1<<endl;
    cout<<"Length of the tree is:-"<<ptr1->get_length()<<endl;
    return 0;
}
