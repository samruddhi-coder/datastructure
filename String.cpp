using namespace std;
#include<iostream>

#include<math.h>
#include<stdlib.h>
#include<string.h>
class Strings
{
	private:
		 char str1[20],str2[20],str3[20];
		 int choice;
	public:
		void accept()
		{
			cout<<"\nEnter String 1:";
			cin>>str1;
			cout<<"\nEnter String 2:";
			cin>>str2;
		}
		void display()
		{
			cout<<"You Entered:\t"<<str1<<" "<<str2;
		}
		void Operation()
		{
            do
            {
                
                cout<<"\n0-Exit\n1-String Compare\n2-String Copy\n3-String Length\n4-String Concatenate\n5-String Reverse\n";
		cout<<"\nEnter your choice :";
                cin>>choice;
                switch(choice)
                {
                    case 0: cout<<"Well Done";
                    break;
			
                    case 1: if(stringCompare(str1,str2)==1)
                            {
                                cout<<"\nYou Entered Equal Strings!"<<endl;
                            }
                            else
                            {
                                cout<<"\nYou Entered Non-equal Strings!"<<endl;
                            }
                    break;
			
                    case 2: cout<<"\n1-Copy First String\n2-Copy Second String\n";
			    cout<<"Which one:1 or 2?";
                            cin>>choice;
                            if(choice==1)
                            {
                                stringCopy(str1,str3);
                                cout<<"\nCopied String is: "<<str3<<endl;
                            }
                            else if(choice==2)
                            {
                                stringCopy(str2,str3);\
                                cout<<"\nCopied String is: "<<str3<<endl;
                            }
                            else
                            {
                                cout<<"Invalid choice!"<<endl;
                            }
                    break;
                    case 3: cout<<"\n1-Length of First String\n2-Length of Second String\n";
			cout<<"Which one:1 or 2?";
                            cin>>choice;
                            if(choice==1)
                            {
                                stringLength(str1);
                            }
                            else if(choice==2)
                            {
                                stringLength(str2);
                            }
                            else
                            {
                                cout<<"\nInvalid choice!";
                            }
                    break;
                    case 4: stringCopy(str1,str3);
                            stringConcatenate(str3,str2);
                            cout<<"\nConcatenated String is: "<<str3<<endl;
                    break;
                    case 5: cout<<"\n1-Reverse First String\n2-Reverse Second String\n";
				cout<<"Which one:1 or 2?";
                            cin>>choice;
                            if(choice==1)
                            {
                                stringCopy(str1,str3);
                            }
                            else if(choice==2)
                            {
                                stringCopy(str2,str3);
                            }
                            else
                            {
                                cout<<"Invalid Choice!"<<endl;
                            }
                            stringReverse(str3);
                            cout<<"Reversed String is: "<<str3<<endl;
                    break;
                    default: cout<<"\nWrong choice!"<<endl;
                }
             
            }while(choice!=0);
	}
		bool stringCompare(char* s1,char* s2)
		{
	        	while(*s1 == *s2)
             		{
                		if((*s1=='\0')&&(*s2=='\0'))
                		{
                    			return true;
                		}		
                	s1++;
                	s2++;
           		}
		     	return false;
		}
		void stringCopy(char* s1,char* s2)
		{
                while(*s1)
                {
                    *s2=*s1;
                    *s1++;
                    *s2++;
                }
            *s2='\0';
		}
		void stringLength(char* s1)
		{
		    int slen1=0;
		    while(*s1)
            {
                *s1++;
                slen1++;
            }
            cout<<"\nLength of String 1: "<<slen1<<endl;
		}
		void stringConcatenate(char* s1,char* s2)
		{
		    while(*s1)
            {
                s1++;
            }
            while(*s2)
            {
                *s1=*s2;
                s2++;
                s1++;
            }
            *s1='\0';
        }
        void stringReverse(char *s1)
        {
            int len=0,i=0;
            char *begin,*end,temp;
            begin=s1;
            end=s1;

                while(*s1)
                {
                    *s1++;
                    len++;
                }
                for(i=0;i<(len-1);i++)
                {
                    end++;
                }
                for(i=0;i<(len/2);i++)
                {
                    temp=*begin;
                    *begin=*end;
                    *end=temp;

                    begin++;
                    end--;
                }
        }
};
int main()
{
	Strings op;
	op.accept();
	op.Operation();
return 0;
}
