#include<iostream>
using namespace std;

int are[100],k;

void displayData(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<are[i]<<" ";
	}
}
void linearSearch(int n)
{
	int item,i,flag=0;
	cout<<"\nEnter the Element to be Searched\n";
	cin>>item;
	for(i=0;i<n;i++)
	{
		if(are[i]==item)
		{
			cout<<"\nElement found at location "<<i+1<<"\n";
			flag=0;
			break;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"\nElement not found\n";
	}
}
void insertionSort(int n)
{
	int i,key,j,k;
cout<<"\n------------Sorted Elements Descending------------";
for(i=1;i<n;i++)
{
key=are[i];
j=i-1;
while(j>=0 && key>are[j])
{
are[j+1]=are[j];
j=j-1;
}
are[j+1]=key;

cout<<"\n Pass"<<i<<":";
for(k=0;k<n;k++)
{
cout<<"\t"<<are[k];
}
cout<<"\n";
}
	
	
}
void selectionSort(int n)
{
	int i,j,min,temp;
		cout<<"\n------------Sorted Elements ascending------------";
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(are[j]<are[min])
			{
				min=j;
			}
		}
		temp=are[i];
		are[i]=are[min];
		are[min]=temp;
		cout<<"\n Pass"<<i+1<<":";
	for(k=0;k<n;k++)
	{
		cout<<"\t"<<are[k];
	}
	cout<<"\n";
	}
	
}

int main()
{
	int n,i,ch;
	cout<<"\nEnter the number of elements: ";
	cin>>n;
	cout<<"\nEnter the Elements in Array: ";
	for(i=0;i<n;i++)
	{
		cin>>are[i];
	}
	//getData(n);
	do
	{
		
		cout<<"\n0-exit\n1-Sort Elements in Ascending order\n2-Sort Elements in Descending Order\n";
		cout<<"3-Search Element\n4-Display Elements\n";
		cout<<"\nEnter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			
			case 0:
				cout<<"exit";
				break;
			case 1:	selectionSort(n);
			break;
			case 2: insertionSort(n);
			break;
			case 3: linearSearch(n);
			break;
			case 4: displayData(n);
			break;
			default: cout<<"\nWrong Choice\n";
		}
		
	}while(ch>0);
	
}
