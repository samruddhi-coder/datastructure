#include<iostream>
using namespace std;
int main()
{
 int i,n,j,a[10],ins;
 cout<<"enter element of array:";
 cin>>n;
 cout<<"enter array element:";
 for(i=0;i<n;i++)
 cin>>a[i];
 for(i=1;i<n;i++)
 {
 ins=a[i];
 j=i-1;
 while(a[j]>ins&&j>=0)
 {
 a[j+1]=a[j];
 j=j-1;
 }
 a[j+1]=ins;
}


for(i=0;i<n;i++)
{
cout<<a[i]<<"\t";
}
}
  
  
 
