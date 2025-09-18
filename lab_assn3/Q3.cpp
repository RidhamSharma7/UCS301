#include <iostream>
#include <string>
using namespace std;


char stackArr[MAX];
int top= 1;

void push(char c)
{ 
stackarr[++top] =c;
 }
char pop(){ 
return stackarr[top--]; 
}

bool isEmpty(){ 
return top==-1; 
}

bool isMatching(char open,char close) {
    return (open=='(' && close==')') ||(open=='[' && close==']') ||(open=='{'&& close=='}');
           
           
}

bool isBalanced(string expr) {
    for(char c: expr) {
        if(c=='('||c=='['||c=='{') {
        	push(c);
		}
        else if(c==')'||c==']'||c=='}') {
            if(isEmpty()||!isMatching(pop(),c)) {
            	return false;
			}
        }
    }
    return isEmpty();
}

int main() {
    string expr="{[()]}";
    if(isBalanced(expr))
    {
    	cout <<"Balanced"<<endl;
	}
else
   {
   	 cout<<"Not Balanced"<<endl;
   }

    return 0;
}
