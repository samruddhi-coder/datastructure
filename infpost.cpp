
#define SIZE 50
#include<iostream>
#include<ctype.h>
using namespace std;


int top=-1;

char s[SIZE];

int push(char c)
{
	s[++top]=c;
return 0;

}

char pop()
{
	return(s[top--]);

}
int priority(char c)
{
	switch(c)
	{
		case '(':	
				return 1;break;	
				
		case '^':	
				return 2;		break;
		case '*':
				return 3; break;
		case '/':
				return 3; break;
		case '+':
				return 4;break;
		case '-':
				return 4; break;
	}
}
		
			
int main()
{
	char postfix[20],infix[20],c,ch;
	int i=0;
	int k=0;
	cout<<"enter the expression";
	cin>>infix;
	push('^');
	for(i=0;infix[i]!='\0';i++)
	{
		ch=infix[i];
		if(ch=='(')
		{
			push(ch);
		}
		else
		{
		
				if(isalnum(ch))
				
				
					postfix[k++]=ch;
				
				else
				{
					if(ch==')')
					{
						while(s[top]!='(')
						
						postfix[k++]=pop();
						c=pop();
					}
					else
					{
				
						while((priority(s[top]))>=(priority(infix[i]))&& top!=-1)
							postfix[k++]=pop();
							push(ch);
								
					}
				}
			}	
			}	
		
		while(s[top]!='^')
			postfix[k++]=pop();
		
		postfix[k]='\0';
		cout<<"Postfix expression"<<postfix;
		return 0;
		
	}





