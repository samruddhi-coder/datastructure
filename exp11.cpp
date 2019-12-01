#include<iostream>
using namespace std;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	

};
struct tree *temp=NULL;

tree *create(tree *temp,int newnode)
{
	//struct tree *temp;
	//int newnode;
	
	if(temp==0)
	{
		temp=new tree;
		temp->left=NULL;
		temp->right=NULL;
		temp->data=newnode;
	}
	
	else
	{
		if(newnode<temp->data)
			temp->left=create(temp->left,newnode);
		
		else if(newnode>temp->data)
			temp->right=create(temp->right,newnode);
		else
			cout<<"duplicate no not allowed ...";
	}
		
	return temp;
}
void inorder(tree *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data;
		inorder(temp->right);
	
	}

}


void preorder(tree *temp)
{
	if(temp!=NULL)
	{
		
		cout<<temp->data;
		preorder(temp->left);
		preorder(temp->right);
	
	}

}


void postorder(tree *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data;
	
	}

}
int main()
{
	//struct tree *n;
	
	int i,n1,newnode;
	cout<<"enter how many nos:";
	cin>>n1;
	for(i=0;i<n1;i++)
	{
		cout<<"enter items";
		cin>>newnode;
		temp=create(temp,newnode);	


	}
	
	cout<<"---------Inorder traversal--------";
	inorder(temp);
	cout<<endl;
	cout<<"----------Preorder traversal---------";
	preorder(temp);
	cout<<endl;
	cout<<"---------Postorder traversal---------";
	postorder(temp);
	return 0;
}






