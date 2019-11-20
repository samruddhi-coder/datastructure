#include<iostream>
using namespace std;

typedef struct student
{
  int rollno,n;
  char name[20];
  char add[20];
  
}s1;
s1 s[100],temp;
int main()
{
  int i,n,pass,pos,rolno,rn,N,ad;
  int flag=1; int ch;
  cout<<"enter how many record:";
  cin>>n;
  
  for(i=0;i<n;i++)
    {
      cout<<"enter rollno,name,add:";
      cin>>s[i].rollno;
      cin>>s[i].name;
      cin>>s[i].add;
    }
  
do
{  
  cout<<"\n 1.sort\n"<<"2.search\n"<<"3.add\n"<<"4.delete\n"<<"5.update\n"<<"6.display\n";
 
  cout<<"enter the choice";
  cin>>ch;
  switch(ch)
  {
  case 1:
  for( pass=0;pass<n-1;pass++)
  {
    
    for(i=0;i<n-pass-1;i++)
    {
      if(s[i].rollno>s[i+1].rollno)
      {
        temp=s[i];
        s[i]=s[i+1];
        s[i+1]=temp;
      }
    }
   }
  cout<<"sortedrecords are:\n";
  for(i=0;i<n;i++)
  {
    
    cout<<s[i].rollno<<"\n";
    cout<<s[i].name;
    cout<<s[i].add<<"\n";
    
  }
  break;
  
  case 2:
  cout<<"BINARY SEARCH";
  int key,first,last,middle;
  cout<<"enter the element to be search:";
  cin>>key;
  first=0;
  last=n-1;
  
  while(first<=last)
  {
     middle=(first+last)/2;
      if(s[middle].rollno<key)
      {
          first=middle+1;
      }
    
      else if(s[middle].rollno==key)
      {
        cout<<key<<"location element found";
        break;
        
        
      }
      else
      {
        last=middle-1;
      }
     }
  if(first>last)
  {
    cout<<"not present";
    break;
  }
  break;
  
  case 3:
  
  n=n+1;
 
  cout<<"enter roll no:";
  cin>>s[n-1].rollno;
  cout<<"enter name:";
  cin>>s[n-1].name;
  cout<<"add";
  cin>>s[n-1].add;
 

  break;
  
  case 4:
  cout<<"enter pos u want to delete";
  cin>>pos;
  for(i=n-1;i>=pos;i--)
  {
  s[i-1]=s[i];
  n=n-1;
  }
  break;
  
  case 5:
    i=0;
    cout<<"enter pos u want to update";
    cin>>rolno;
    while(i<n-1)
    {
    if(s[i].rollno==rolno)
    {
    cin>>s[i].rollno;
    cin>>s[i].name;
    cin>>s[i].add;
    }
    i++;
    }
    
  break;
  case 6:
  for(i=0;i<n;i++)
  {
  cout<<s[i].rollno<<"\n";
  cout<<s[i].name<<"\n";
  cout<<s[i].add<<"\n";
  }
  break;
  
  
  
  default:
  cout<<"invalid";
  break;
}
}while (ch<=6);
}
