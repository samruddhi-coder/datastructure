#include<iostream>
using namespace std;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	

};

struct tree *create()
{
	struct tree *temp;
	int newnode;
	cout<<"enter data:  ";
	cin>>newnode;
	if(newnode==0)
	{
		return NULL;
	}
	temp=new tree;
	temp->data=newnode;
	temp->left=NULL;
	temp->right=NULL;
	
	cout<<"enter left sub tree:  \n";
	temp->left=create();
	cout<<"enter right sub tree:  ";
	temp->right=create();
	return temp;
}
void inorder(tree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->data;
		inorder(t->right);
	
	}

}


void preorder(tree *t)
{
	if(t!=NULL)
	{
		
		cout<<t->data;
		preorder(t->left);
		preorder(t->right);
	
	}

}


void postorder(tree *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout<<t->data;
	
	}

}
int main()
{
	struct tree *n;
	n=create();
	cout<<"---------Inorder traversal--------";
	inorder(n);
	cout<<endl;
	cout<<"----------Preorder traversal---------";
	preorder(n);
	cout<<endl;
	cout<<"---------Postorder traversal---------";
	postorder(n);
	return 0;
}






