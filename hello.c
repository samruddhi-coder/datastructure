#include<iostream>

Struct student
{
  int rollno;
  char name[20];
  char add[20];
  
}s[100];
void main()
{
  cout<<"enter how many record";
  cin>>n;
  
  for(i=0;i<n;i++)
    {
      cout<<"enter rollno,name,add";
      cin>>s[i].rollno>>s[i].name>>s[i].add;
    }
}
