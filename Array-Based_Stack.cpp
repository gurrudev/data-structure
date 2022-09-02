
#include<iostream>
#include<conio.h>
#define MAX 4
using namespace std;

//2. Stack Template 
class AStack{
	int A[MAX];
	int tos;
	
	public:
		AStack(){
			tos=-1;
		} 	
		void Push(int x);
		void Pop();
		void Peek();
		void Display();
		int Full();
		int Empty();
};
//3. Function
int AStack::Full(){
	if(tos==MAX-1){
		return 1;
	}else{
		return 0;
	}
}//end of Full()

void AStack::Push(int x){
	if(Full()){
		cout<<"Stack Overflow!";
	}else{
		tos++;
		A[tos]=x;
	}
}//end of Push()

int AStack::Empty(){
	if(tos==-1){
		return 1;
	}else{
		return 0;
	}
}//end of Empty()

void AStack::Pop(){
	if(Empty()){
		cout<<"Stack Underflow!";
	}else{
		int tmp =A[tos];
		tos--;
		cout<<"Element popped is: "<<tmp;
	}
}//end of Pop()

void AStack::Display(){
	if(Empty()){
		cout<<"Stack Underflow!";
	}else{
		cout<<"Stack: ";
		for(int i=tos; i>=0; i--){
			cout<<A[i]<<" ";
		}
	}
}//end of Display()
void AStack :: Peek()
{
	if(Empty())
	{
		cout << "Stack Underflow";
	}
	else
	{
		cout << "Element at the top: " << A[tos];
	}
}//end of Peek()

//4. Menu
int main(){
	AStack s;
	int num, ch;
	
	while(1){
		system("cls");
		cout<<"\n******Array based stack****\n\n";
		cout<<"1. Push an element on the stack\n";
		cout<<"2. Pop Operation\n";
		cout<<"3. Peek at the stack\n";
		cout<<"4. Display the stack\n";
		cout<<"5. Exit\n\n";
		
		cout <<"Enter Your Choice : ";
		cin >> ch;
		switch(ch){
			case 1:	cout<<"=Enter a value: ";
					cin>>num;
					s.Push(num);
					getch();
					break;
					
			case 2: s.Pop();
					getch();
					break;
					
			case 3: s.Peek();
					getch();
					break;
					
			case 4: s.Display();
					getch();
					break;
					
			case 5: exit(1);
			
			default:cout <<"Incorrect Choice";
					getch();
					break;
		}//end of switch()
	}//end of while()
}//end of main()

