#include <iostream>
#include <string>
using namespace std;


char stackarr[MAX];
int top=-1;

void push(char c)
{ stackarr[++top] =c;
 }
char pop(){ 
return stackarr[top--]; 
}

int main() {
    char str[]="DataStructure";
    int n=strlen(str);

    
    for(int i=0;i<n;i++){
    	 push(str[i]);
	}

    cout<<"reversed:";
    while(top != -1) {
    	cout << pop()<<endl;
	}
    

    return 0;
}
