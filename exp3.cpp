//Array of stucture



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
  cout<<"ENTER THE NO. OF RECORDS: \n";
  cin>>n;
  
  for(i=0;i<n;i++)
    {
      cout<<"ENTER YOUR ROLLNO,NAME,ADDRESS: \n";
      cin>>s[i].rollno;
      cin>>s[i].name;
      cin>>s[i].add;
    }
  
do
{  
  cout<<"\n------------CHOICES-----------";
  cout<<"\n0.Exit\n1.Sort\n"<<"2.Search\n"<<"3.Add\n"<<"4.Delete\n"<<"5.Update\n"<<"6.Display\n";
 
  cout<<"ENTER YOUR CHOICE: ";
  cin>>ch;
  switch(ch)
  {
  case 0:
	cout<<"EXIT\n";
	break;
  case 1:cout<<"---------BUBBLE SORT----------\n";
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
  cout<<"SORTED RECORDS ARE:\n";
	cout<<"rollno  "<<"name  "<<"address  \n";
  for(i=0;i<n;i++)
  {
    
    cout<<s[i].rollno<<"\t";
    cout<<s[i].name<<"\t";
    cout<<s[i].add<<endl;
    
  }
  break;
  
  case 2:cout<<"---------SEARCHING RECORD----------\n";
  
  int key,first,last,middle;
  cout<<"ENTER ROLLNO TO BE SEARCHED: \n";
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
        cout<<"LOCATION ELEMENT FOUND\n";
	cout<<"Rollno:"<<s[middle].rollno<<" ";
	cout<<"Name:"<<s[middle].name<<" ";
	cout<<"Address:"<<s[middle].add;
        break;
        
        
      }
      else
      {
        last=middle-1;
      }
   }
  if(first>last)
  {
    cout<<"ELEMENT NOT PRESENT";
    break;
  }
  break;
  
  case 3:cout<<"---------ADDING RECORD----------\n";
  
  n=n+1;
 
  cout<<"enter roll no: ";
  cin>>s[n-1].rollno;
  cout<<"enter name: ";
  cin>>s[n-1].name;
  cout<<"enter address: ";
  cin>>s[n-1].add;
 

  break;
  
  case 4:cout<<"---------DELETING RECORD----------\n";
  
  cout<<"ENTER POSITION YOU WANT TO DELETE: \n";
  cin>>pos;
  for(i=pos-1;i<n-1;i++)
  {
  	s[i]=s[i+1];
  	
  }
  n=n-1;
  

  break;
  
  case 5:cout<<"---------UPDATING RECORD----------\n";
    
    i=0;
    cout<<"ENTER ROLLNO YOU WANT TO UPDATE: \n";
    cin>>rolno;
    while(s[i].rollno!=rolno)
    {
   
   	 i++;
    }
    cout<<"ENTER NEW RECORD";
    cin>>s[i].rollno;
    cin>>s[i].name;
    cin>>s[i].add;
	
    
  break;
  case 6:cout<<"---------DISPLAYING RECORD----------\n";
  cout<<"THE RECORDS ARE: \n";
	cout<<"rollno  "<<"name  "<<"address  \n";
  for(i=0;i<n;i++)
  {
  cout<<s[i].rollno<<"\t";
  cout<<s[i].name<<"\t";
  cout<<s[i].add<<"\n";
  }
  break;
  
  
  
  default:
  cout<<"invalid";
  break;
}
}while (ch!=0);
}






























