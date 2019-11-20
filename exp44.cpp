#include<iostream>
using namespace std;
void ascending(int a[],int n)
{
int i,j,k,temp,minIndex;
for(i=0;i<n-1;i++)
{
minIndex=i;
for(j=i+1;j<n;j++)
{
if(a[j]<a[minIndex])
minIndex=j;
}
temp=a[i];
a[i]=a[minIndex];
a[minIndex]=temp;
cout<<"\n Pass"<<i+1<<":";
for(k=0;k<n;k++)
{
cout<<"\t"<<a[k];
}
cout<<"\n";
}
}
void descending(int a[],int n)
{
int i,key,j,k;
for(i=1;i<n;i++)
{
key=a[i];j=i-1;
while(j>=0 && key>a[j])
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=key;
cout<<"\n Pass"<<i<<":";
for(k=0;k<n;k++)
{
cout<<"\t"<<a[k];
}
cout<<"\n";
}
}
void search(int a[],int n)
{
int i,flag=0,key;
cout<<"\n Enter Key to be found:";
cin>>key;
for(i=0;i<n;i++)
{
if(a[i]==key)
flag=1;
}
if(flag==1)
cout<<"\n Key found";
else
cout<<"\n Key not found";
}
int main()
{
int a[20],n,i,ch;
cout<<"\n Enter No. of elements:";
cin>>n;
cout<<"\n Enter elements:";
for(i=0;i<n;i++)
	cin>>a[i];
do
{
cout<<"\n 1.Ascending \n 2.Descending \n 3.Search ";
cout<<"\n Enter choice:";
cin>>ch;
switch(ch)
{
case 1:
ascending(a,n);
break;
case 2:
descending(a,n);
break;
case 3:
search(a,n);
break;
default:
cout<<"\n Inavalid choice";
break;
}
}while(ch<=3);
return 0;
}
