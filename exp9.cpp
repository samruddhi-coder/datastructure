#include<ctype.h>
#include<iostream>
using namespace std;

char s[50],infix[50],postfix[50],ch;
int i,top=-1,k=0;

char push(char ch)
{
   s[++top]=ch;
}

char pop()
{
   return s[top--];
}

int pr(char ch)
{
   switch(ch)
   {
       case'(':
               return 1;
               break;
       case'+':
       case'-':
               return 2;
               break;
       case'*':
       case'/':
               return 3;
               break;
       case'^':
       case'%':
               return 4;
               break;
   }
}

int main()
{
  cout<<"\nEnter Infix Expression: ";
  cin>>infix;
  for(i=0;infix[i]!='\0';i++)
  {
     ch=infix[i];
     if(ch=='(')
     {
          push(ch);
     }
     else
        if(isalnum(ch))
        {
          postfix[k++]=ch;
        }
        else
        if(ch==')')
	{
		while(s[top]!='(')
			postfix[k++]=pop();
		pop();
	}
         else
           {
                while(pr(ch)<=pr(s[top]) && top!=-1)
                 postfix[k++]=pop();
                 push(ch);
             
           }
      
  }
    while(s[top]>=0)
    {
       postfix[k++]=pop();
    }
  postfix[k++]='\0';
  cout<<"\nPostfix Expression is  "<<postfix;
  return 0;
}







