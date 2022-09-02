
#include<iostream>
#include<conio.h>
using namespace std;
//1.Node template
class SNode
{
	public:
		int data;
		SNode *next;
};//end of Node template

//2.Class Template
class LStack
{
	SNode *tos;
	
	public:
			LStack()
			{
				tos = NULL;
			}
			void Push(int x);
			void Pop();
			void Peek();
			void Display();
			int Empty();
	
};//end of class template

//3.Functions
void LStack :: Push(int x)
{
	//create a node
	SNode *t = new SNode();
	
	t->data = x;
	t->next = NULL;
	
	//check if it is the 1st Node in the stack
	if(tos == NULL)
	{
		tos = t;
	}
	else
	{
		t->next = tos;
		tos = t;
	}
}//end of push method

int LStack :: Empty()
{
	if(tos == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//end of empty

void LStack :: Pop()
{
	if(Empty())
	{
		cout << "List is Empty!";
	}
	else
	{
		SNode *tmp = tos;
		
		tos = tos->next;
		
		cout << "Element Popped : " <<tmp->data;
		delete tmp;
	}
}//end of pop

void LStack :: Peek()
{
	if(Empty())
	{
		cout << "List is Empty!";	
	}
	else
	{
		cout << "Element at the TOP is : " << tos->data;
	}
}//end of peek

void LStack :: Display()
{
	if(Empty())
	{
		cout << "List is Empty!";
	}
	else
	{
		cout << "Stack : " << endl;
		
		SNode *tmp = tos;
		
		while(tmp!=NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
	}
}//end of display


//4.Menu
int main()
{
	LStack s;
	int num,ch;
	
	while(1)
	{
		system("cls");
	
		cout << "*****List Based Stack*****\n";
		
		cout << "1.Push and element into the stack.\n";
		cout << "2.Pop the element from the stack.\n";
		cout << "3.Peek at the stack.\n ";
		cout << "4.Display the stack.\n";
		cout << "5.Exit\n";
		
		cout << "Enter Your Choice : ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter a Number to insert : ";
				cin >> num;
				s.Push(num);
				getch();
				break;
			case 2:
				cout << "Popping is Happening...\n";
				s.Pop();
				getch();
				break;
			case 3:
				cout << "Pekking ...\n";
				s.Peek();
				getch();
				break;
			case 4:
				cout << "Displaying the Stack : ";
				s.Display();
				getch();
				break;
			case 5:
				cout << "Program Closed!";
				exit(1);
			default :
				cout << "Incorrect Choice";
				getch();
				break;
		}
	}
}
