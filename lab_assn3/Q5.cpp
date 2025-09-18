#include <iostream>
#include <cctype>
using namespace std;

int st[MAX], top=-1;

int main(){
    char exp[]="23*54*+9-";   
    for(int i=0;exp[i];i++){
        char c=exp[i];
        if(isdigit(c)) {
        	st[++top]=c-'0';
		}
        else{
            int b=st[top--];
			int a=st[top--];
            if(c=='+') {
            	st[++top]=a+b;
			}
            else if(c=='-'){
            	 st[++top]=a-b;
			}
            else if(c=='*') {
            	st[++top]=a*b;
			}
            else if(c=='/'){
            	st[++top]=a/b;
			}
        }
    }
    cout<<"Result: "<<st[top];
}
