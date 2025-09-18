#include <iostream>
using namespace std;

char st[MAX]; 
int top=-1;

int prec(char c){
    if(c=='+'||c=='-') {
    	return 1;
	}
    if(c=='*'||c=='/') {
    	return 2;
	}
    return 0;
}

bool isOperand(char c){
    return (c>='A' && c<='Z')||(c>='a' && c<='z') || (c>='0'&& c<='9'); 
           
           
}

int main(){
    char in[]="A*(B+C)", 
	post[50]; int k=0;
    for(int i=0;in[i];i++){
        char c=in[i];
        if(isOperand(c)){
        	 post[k++]=c;
		}         
        else if(c=='(') {
        	st[++top]=c; 
		}          
        else if(c==')'){                       
            while(st[top]!='('){
            	 post[k++]=st[top--];
			}
            top--; 
        }
        else{                                  /
            while(top!=-1 && prec(st[top])>=prec(c))
               {
               	 post[k++]=st[top--];
			   }
            st[++top]=c;
        }
    }
    while(top!=-1) {
    	post[k++]=st[top--];
	}
    post[k]='\0';

    cout<<"Postfix: "<<post;
}
