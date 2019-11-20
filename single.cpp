#include <iostream>

using namespace std;

struct node
{
 int Rollno;
 double grno;
 string name;
 struct node *next;
 }*head=NULL;
 
int main()
{
 struct node *nn,*temp;
 char ans='n';
 do
 	{
 		nn=new node;
 
		cout<<"Enter Rollno"<<endl;
 		cin>>nn->Rollno;
 		cout<<"Enter grno"<<endl;
 		cin>>nn->grno;
		cout<<"Enter name"<<endl;
 		cin>>nn->name;
 		nn->next=NULL;

	 if (head==NULL)
 		{
		 head=nn;
		 }
 		else
		{
 	temp= head;

 	while(temp->next !=NULL)
 	{
  		temp=temp->next;
  	}
  		temp->next=nn;
 }
  cout<<"Enter more nodes?"<<endl;
  cin>>ans;
  }while(ans=='y');
temp=head;
while(temp!=NULL)

  {
  cout<<temp->Rollno;
  cout<<temp->grno;
  cout<<temp->name;
  temp=temp->next;
  }
  return 0;
  }
  
  
