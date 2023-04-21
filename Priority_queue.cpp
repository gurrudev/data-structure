	
#include<iostream>
#include<conio.h>
using namespace std;
//1. Node Temp
class PQNode{
	public:
		int data;
		int priority;
		PQNode *next;
}; 
//2. Queue Temp
class PQueue{
	PQNode *front; 
	 
	public:
		PQueue(){
			front = NULL;
		}
		void Enqueue(int x,int p);
		void Dequeue();
		void Display();
		int Empty();
};
//3. Functions
void PQueue :: Enqueue(int x,int p)
{
	//make a new Node
	PQNode *t = new PQNode();
	t->data = x;
	t->priority = p;
	t->next = NULL; 
	
	//First node in PriorityQ
	if(front == NULL)
	{
		front = t;
		return;
	}
	
	PQNode *tmp = front;
	PQNode *prev = NULL;
	
	while(tmp && tmp->priority<t->priority)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	
	//t inserted in rear
	if(tmp == NULL)
	{
		prev->next = t;
	}
	//t inserted at the front
	else if(prev == NULL)
	{
		t->next = front;
		front = t;
	}
	//t inserted in the middle
	else
	{
		prev->next=t;
		t->next = tmp;
	}
}//end of enqueue

int PQueue :: Empty()
{
	if(front == NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}//end of empty

void PQueue :: Dequeue()
{
	if(Empty())
	{
		cout << "Queue is Empty !!";
		return;
	}
	
	PQNode *tmp = front;
	if(front->next == NULL)
	{
		front = NULL;
	}
	else
	{
		front = front->next;
	}
	cout << "Element deleted is : " << tmp->data;
	delete tmp; 	
}

void PQueue :: Display()
{
	if(Empty())
	{
		cout << "Queue is Empty!!";
		return;
	}
	PQNode *tmp = front;
	if(Empty())
	{
		cout << "Queue is Empty !!";
		return;
	}
	
	while(tmp)
	{
		cout << tmp->data << " " << tmp->priority << " ";
		tmp = tmp->next;
	}
}

//4. menu

int main(){ 
	PQueue q;
	int num,ch,pri;
	
	while(1){
		system("cls");
		
		cout << "*****Priority Queue*****\n\n";
		
		cout << "1. Enqueue.\n";
		cout << "2. Dequeue.\n";
		cout << "3. Display the queue.\n";
		cout << "4. Exit\n";
		
		cout << "\nEnter Your Choice : ";
		cin >> ch;
		cout << endl;
		
		switch(ch){
			case 1: cout << "Enter a Number to insert : ";
					cin >> num;
					cout << "Enter priority of element : ";
					cin >> pri;
					q.Enqueue(num,pri);
					getch();
					break;
			case 2:	
					q.Dequeue();
					getch();
					break;
			case 3:		
					cout << "Displaying the Elements : ";
					q.Display();
						
					getch();
					break;
			case 4: exit(1);
			default :
				cout << "Incorrect Choice";
				getch();
				break;
		}
	}
	
}

