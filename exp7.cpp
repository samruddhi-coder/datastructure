#include<iostream>

using namespace std;

struct node
{
	
	int roll_no;
	char name[20];
	char br[20];
 struct node *next;
 }*head=NULL;
 
 void create()
 {
	cout<<"--------CREATE NODE--------\n";
	struct node *temp,*new_node;
	new_node=new node;
	cout<<"\n Enter Roll No.:";
	cin>>new_node->roll_no;	
	cout<<"\n Enter Name:";
	cin>>new_node->name;
	cout<<"\n Enter Branch:";
	cin>>new_node->br;
	new_node->next=NULL;
 	
 	if(head==NULL)
 	{
 		head=new_node;
 	}
 	else
 	{
 		temp=head;
 		while(temp->next!=NULL)
 		{
 			temp=temp->next;
 			temp->next=new_node;
 		}
 	}
 }

void display()
{
	cout<<"--------DISPLAY DATA--------\n";
	struct node *temp;
	temp=head;
	if(head==NULL)
		cout<<"\n List is empty";
	else
	{
		temp=head;
		cout<<"\n Student Data:";
	
		cout<<"\n=====================================";
		cout<<"\n Roll No.\t Name \t Branch";
		cout<<"\n=====================================";
	while(temp!=NULL)
	{
		
		cout<<"\n\t"<< temp->roll_no<<"\t"<<temp->name<<"\t"<<temp->br;
		temp=temp->next;
		
	}
	cout<<endl;
}
}

void insert_beg()
{
	cout<<"--------INSERT AT BEGINNING--------\n";
	struct node *new_node;
	new_node=new node;
	cout<<"Enter Roll no: ";
	cin>>new_node->roll_no;
	cout<<"\nEnter Name:";
	cin>>new_node->name;
	cout<<"\nEnter Branch:";
	cin>>new_node->br;
	new_node->next=NULL;	
	new_node->next=head;
	head=new_node;
	cout<<"data inserted";
	
}

void insert_pos()
{
	cout<<"--------INSERT AT POSITION--------\n";
	int pos,i=1;
	struct node *temp,*new_node;
	new_node=new node;
	cout<<"Enter Roll no: ";
	cin>>new_node->roll_no;
	cout<<"\nEnter Name:";
	cin>>new_node->name;
	cout<<"\nEnter Branch:";
	cin>>new_node->br;
	new_node->next=NULL;	
	cout<<"Enter Position: ";
	cin>>pos;
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	cout<<"data inserted";
}
void insert_end()
{
	cout<<"--------INSERT AT END--------\n";
	struct node *temp,*new_node;
	new_node=new node;
	cout<<"Enter Roll no: ";
	cin>>new_node->roll_no;
	cout<<"\nEnter Name:";
	cin>>new_node->name;
	cout<<"\nEnter Branch:";
	cin>>new_node->br;
	new_node->next=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	cout<<"data inserted";
}

void del_first()
{
	cout<<"--------DELETE AT FIRST--------\n";
	struct node *temp;
	temp=head;
	head=head->next;
	temp->next=NULL;
	delete(temp);
	cout<<"data deleted";
}	
void del_pos()
{
	cout<<"--------DELETE AT POSITION--------\n";
	struct node *temp,*t;
	int pos,i=1;

	cout<<"\n Enter position of deletion:";
	cin>>pos;
	temp=head;
	while(i<pos)
	{
		t=temp;
		temp=temp->next;
		i++;
	}
	t->next=temp->next;
	temp->next=NULL;
	delete(temp);
}
void del_end()
{
	cout<<"--------DELETE AT END--------\n";
	struct node *temp,*t;
	temp=head;
	while(temp->next!=NULL)
	{
		t=temp;
		temp=temp->next;
	}
	t->next=NULL;
	delete(temp);
	cout<<"data deleted";		

}

void update()
{
	cout<<"--------UPDATE DATA--------\n";
	int key;
	struct node *temp;
	temp=head;
	cout<<"Enter rollno of which data to be changed: ";
	cin>>key;
	while(temp->roll_no!=key)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"Data not found\n";
	
	}
	else
	{
		cout<<"--Enter New Data--\n";
		cout<<"Enter name:\n";
		cin>>temp->name;
		cout<<"Enter branch:\n\n";
		cin>>temp->br;
		
		
		cout<<"successfully modified\n";

		
	}
	
	

}
void search()
{
	cout<<"---------SEARCHING DATA--------";
	struct node *temp;
	int key,cnt=0;
	bool flag=false;
	

	cout<<"Enter rollno to be Search";
	cin>>key;
	temp=head;
	while(temp->next!= NULL)
	{
		if(temp->roll_no==key)
		{
			cout<<"\nItem Searched";
			//cout<<"Data: "<<temp->data;
			temp->next;
			flag=true;
			break;
		}
		//cnt++;
		temp=temp->next;
	}
	if(flag==false)
	{
		cout<<"\nnot present item";
	}
	

}

 int main()
 {
 		
 	head=NULL;
	int choice;
	do
	{
		cout<<"--------CHOICE---------\n";
		cout<<"1.create node in list"<<endl;
		cout<<"2.display data"<<endl;
		cout<<"3.insert node at begin"<<endl;
		cout<<"4.insert node at specific position"<<endl;
		cout<<"5.insert node at end"<<endl;
		cout<<"6.delete node at begin"<<endl;
		cout<<"7.delete node at specific position"<<endl;
		cout<<"8.delete node at end"<<endl;
		cout<<"9.update node"<<endl;
		cout<<"10.search a node"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;
		switch(choice)

		{

			case 1:
					create();
					break;

			case 2:
					display();
					break;
			case 3:
					insert_beg();
					break;
			case 4:
					insert_pos();
					break;
			case 5:
					insert_end();
					break;
			case 6:
					del_first();
					break;
			case 7:
					del_pos();
					break;
			case 8:
					del_end();
					break;
			case 9:
					update();
					break;
			case 10:
					search();
					break;
			 default:
  				cout<<"invalid";
 			 break;
		}
	}while(choice!=0);
}
