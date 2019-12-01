
#include<iostream>
using namespace std;
struct poly
{
int coeff,exp;
struct poly *next;
}*h1=NULL,*h2=NULL,*h3=NULL;

int total_terms1,total_terms2,total_terms3;

void create_poly()
{
struct poly *new_node,*temp;
int i;
new_node = new poly ;
cout<<"Enter no. of terms in polynomial 1:"<<endl;
cin>>total_terms1;
for(i=0;i<total_terms1;i++)
{

new_node=new poly;
cout<<"Enter coefficient:"<<endl;
cin>>new_node->coeff;
cout<<"Enter Exponent:"<<endl;
cin>>new_node->exp;
new_node->next=NULL;
if(h1==NULL)
{
h1=new_node;
new_node->next=h1;
}
else
{
temp=h1;
while(temp->next!=h1)
temp=temp->next;
temp->next=new_node;
new_node->next=h1;
}
}

cout<<"\nEnter no. of terms in polynomial 2:"<<endl;
cin>>total_terms2;
for(i=0;i<total_terms2;i++)
{
new_node=new poly;
cout<<"Enter coefficient:"<<endl;
cin>>new_node->coeff;
cout<<"Enter Exponent:"<<endl;
cin>>new_node->exp;
new_node->next=NULL;
if(h2==NULL)
{
h2=new_node;
new_node->next=h2;
}
else
{
temp=h2;
while(temp->next!=temp)
temp=temp->next;
temp->next=new_node;
new_node->next=h2;
}
}
}

void addition()
{
int flag,i,j;
struct poly *t1,*t2,*t3,*new_node;
t1=h1;
t2=h2;
for(i=0;i<total_terms1;i++)
{
flag=0;
t2=h2;
for(j=0;j<total_terms2;j++)
{
if(t1->exp==t2->exp)
{
new_node=new poly;
new_node->exp=t1->exp;
new_node->coeff=t1->coeff+t2->coeff;
new_node->next=NULL;
if(h3==NULL)
{
h3=new_node;
new_node->next=h3;
}
else
{
t3=h3;
while(t3->next!=h3)
t3=t3->next;
t3->next=new_node;
new_node->next=h3;
}
flag=1;
}
t2=t2->next;
}
if(flag==0)
{
new_node=new poly;
new_node->coeff=t1->coeff;
new_node->exp=t1->exp;
if(h3==NULL)
{
h3=new_node;
new_node->next=h3;
}
else
{
t3=h3;
while(t3->next!=h3)
t3=t3->next;
t3->next=new_node;
new_node->next=h3;
}
}
t1=t1->next;
}
t2=h2;
for(j=0;j<total_terms2;j++)
{
flag=0;
t1=h1;
for(i=0;i<total_terms1;i++)
{
if(t2->exp==t1->exp)
flag=1;
t1=t1->next;
}
if(flag==0)
{
new_node=new poly;
new_node->coeff=t2->coeff;
new_node->exp=t2->exp;
if(h3==NULL)
{
h3=new_node;
new_node->next=h3;
}
else
{
t3=h3;
while(t3->next!=h3)
t3=t3->next;
t3->next=new_node;
new_node->next=h3;
}
}
t2=t2->next;
}


}

void display_add()
{
struct poly *temp;
temp=h3;
cout<<"\nPolynomial addition is:";
cout<<temp->coeff<<" x^"<<temp->exp;
temp=temp->next;
while(temp!=h3)
{
cout<<" + "<<temp->coeff<<" x^"<<temp->exp;
temp=temp->next;
}
cout<<endl;
}

int exponent(int exp ,int x)
{
int product=1;
while(exp!=0)
{
product=product*x;
exp--;
}
return product;
}

void evaluation()
{
int key,temp1,result,sum=0;
struct poly *temp;
temp=h1;
cout<<"\nEnter value of x:"<<endl;
cin>>key;
do
{
temp1=exponent(temp->exp,key);
result=temp1* temp->coeff;
sum+=result;
temp=temp->next;
}while(temp!=h1);
cout<<"Value of Ploynomial is:"<<sum<<endl;
}

void evaluation2()
{
int key,temp1,result,sum=0;
struct poly *temp;
temp=h2;
cout<<"\nEnter value of x:"<<endl;
cin>>key;
do
{
temp1=exponent(temp->exp,key);
result=temp1* temp->coeff;
sum+=result;
temp=temp->next;
}while(temp!=h2);
cout<<"Value of Ploynomial is:"<<sum<<endl;
}

int main()
{
create_poly();
cout<<"\nPloynimial created successfully!!"<<endl;

while(true)
{
cout<<"\nEnter 1 to Add Polynomials:\nEnter 2 to Evaluate a Polynomial:\nEnter 3 to Exit:\n";
int choice;
cin>>choice;
switch(choice)
{
case 1:
addition();
cout<<"\nPloynimials added successfully!!"<<endl;
display_add();
break;

case 2:
cout<<"\nEnter 1 for selecting 1st polynomial entered, as base for evaluation:\nEnter 2 for selecting 2nd polynomial entered, as base for evaluation:"<<endl;
int i;
cin>>i;
if(i==1)
evaluation();
else if(i==2)
evaluation2();
else
cout<<"Wrong Input!!";
break;

case 3:
return 0;

default:
cout<<"Wrong Input!!\n";
}
}

return 0;
}
