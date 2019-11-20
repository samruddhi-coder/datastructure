//PROGRAM:


using namespace std;
#include<iostream>
//#include<conio.h>
#include<stdlib.h>

int main()
{
    int m[10][10],sp[10][10];
 
    int i,j;
    int r,c,nonZero=0,ctr=1;
    cout<<"\nEnter the number of rows in the matrix: ";
    cin>>r;
    cout<<"\nEnter the number of Columns in the matrix: ";
    cin>>c;
    cout<<"\nEnter the Elements in the matrix: ";
    //cout<<"------------sparse matrix";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>m[i][j];
            cout<<"\t";
        }
        cout<<"\n";
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                nonZero++;
            }
        }
    }

    sp[0][0]=r;
    sp[0][1]=c;
    sp[0][2]=nonZero;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                sp[ctr][0]=i;
                sp[ctr][1]=j;
                sp[ctr][2]=m[i][j];
                ctr++;
            }
        }
    }
cout<<"sparse matrix represented as:\n";
    for(i=0;i<ctr;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<sp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
    //simple transpose
	int b[10][10],nxt;

	
	b[0][0]=sp[0][1];
	b[0][1]=sp[0][0];
	b[0][2]=sp[0][2];
	
	if(sp[0][0]>1)
	{
		nxt=1;
		for(int pass=0;pass<c;pass++)
		{
			for(i=0;i<=nonZero;i++)
			{
				if(sp[i][1]==pass)
				{
					b[nxt][0]=sp[i][1];
					b[nxt][1]=sp[i][0];
					b[nxt][2]=sp[i][2];
					nxt++;
				}

			}
		}
	}
cout<<"simple transpose of matrix represented by:\n";
  for(i=0;i<=nonZero;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<b[i][j]<<"\t";
        }
        cout<<"\n";
    }


	//fast transpose
int rowterm[100],start_pos[100],t,u,numterm=sp[0][2];
int fast[10][10];
fast[0][0]=sp[0][1];
fast[0][1]=sp[0][0];
fast[0][2]=sp[0][2];
if(numterm>0)
{

for(i=0;i<c;i++)
{
	rowterm[i]=0;
}

for(i=1;i<=numterm;i++)
{
	rowterm[sp[i][1]]++;

}
start_pos[0]=1;
for(i=1;i<c;i++)
	start_pos[i]=start_pos[i-1]+rowterm[i-1];
for(i=1;i<=numterm;i++)
{
	u=start_pos[sp[i][1]]++;
	
	fast[u][0]=sp[i][1];
	fast[u][1]=sp[i][0];
	fast[u][2]=sp[i][2];

}
}



cout<<"fast transpose of matrix represented by:\n";
 

    for(i=0;i<=numterm;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<fast[i][j]<<"\t";
        }
        cout<<"\n";
    }
return 0;
}
