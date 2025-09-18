#include <iostream>
using namespace std;

int stackArr[MAX];
int top= -1;

bool isEmpty(){
 return top==-1; }
bool isFull() 
{ return top == MAX-1; 
}

void push(int x) {
    if (isFull()) 
    {
    	cout<<"Stack Overflow\n";
	}
    else {
    	stackArr[++top] = x;
	}
}

void pop() {
    if (isEmpty()){
    	cout<< "Stack Underflow\n";
	}
    else{
    	cout<<"Popped: " <<stackArr[top--]<<endl;
	}
}

void peek() {
    if (isEmpty()) 
    {
    	cout<<"Stack is empty\n";
	}
    else {
    	cout <<"Top element: "<<stackArr[top]<<endl;
	}
}

void display() {
    if (isEmpty()) 
    {
    	cout<<"Stack is empty\n";
	}
    else {
        cout<<"Stack elements: ";
        for (int i=top; i>= 0; i--) 
        {
        	cout<<"Stack is empty\n";
		}
        
    }
}

int main() {
    int choice, val;
    do {
        
        cout<<"1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout<<"Enter choice:";
        cin>>choice;

        if(choice==1) {
            cout<<"add value: "; 
			cin >> val;
            push(val);
        }
        else if(choice== 2) 
		{
			pop();
		}pop();
        else if(choice==3) cout << (isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n");
        else if(choice==4) cout << (isFull() ? "Stack is Full\n" : "Stack is not Full\n");
        else if(choice==5) display();
        else if(choice==6) peek();
        else if(choice==7) 
        {
        	cout<< "exits";
		}
        else{
         cout<<"invalid";
		}

    } while(choice!= 7);

    return 0;
}

