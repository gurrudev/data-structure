
#include<iostream>
#include<conio.h>

#define MAX 4 
using namespace std;

//1.Node Template
//2.class Template
class OQueue
{
	int A[MAX];
	int front;
	int rear;
	
	public:
			OQueue()
			{
				front = -1;
				rear = -1;
				
			}
			
			void Enqueue(int x);
			void Dequeue();
			void PeekFront();
			void PeekRear();
			void Display();
			int Full();
			int Empty();
			
};//end of class

//3.Functions
int OQueue :: Full()
{
	if(rear == MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//end of full

int OQueue :: Empty()
{
	if(front == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//end of empty 

void OQueue :: Enqueue(int x)
{
	if(Full())
	{
		cout << "Queue OverFLow.\n";
		return;
	}
	if(Empty())
	{
		front++;
	}
	rear++;
	A[rear] = x;
}//end of enqueue


void OQueue :: PeekFront()
{
	if(Empty())
	{
		cout << "Empty Queue.\n";
		return;
	}
	
	cout << "Element in the Front is : " << A[front];
	
} //end of peekfront

void OQueue :: PeekRear()
{
	if(Empty())
	{
		cout << "Empty Queue\n";
		return;
	}
		
	cout << "Element at rear is : " << A[rear];
}//end of peekrear

void OQueue :: Dequeue()
{
	if(Empty())
	{
		cout << "Queue is Empty.\n";
		return;
	}
	int tmp = A[front];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front++;
	}
	
	cout << "Dequeued Element is : " << tmp;
}//end of dequeue

void OQueue :: Display()
{
	if(Empty())
	{
		cout << "Queue is Empty.";
		return;
	}
	for(int i=front;i<=rear;i++)
	{
		cout << A[i] << " ";
	}
}//end of display

//4.Menu

int main()
{
	OQueue o;
	int num,ch;
	
	while(1)
	{
		system("cls");
		
		cout << "*****Ordinary Queue*****" << endl;
		
		cout << "1.Enter an eleemnt into the queue.\n";
		cout << "2.Dequeue the element from the queue\n";
		cout << "3.Peek in the front of the queue\n";
		cout << "4.Peek in the rear of the queue\n";
		cout << "5.Display the queue.\n";
		cout << "6.Exit the Program.\n\n";
		
		cout << "Enter your choice : ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter an element : ";
				cin >> num;
				o.Enqueue(num);
				getch();
				break;
			case 2:
				o.Dequeue();
				getch();
				break;
			case 3:
				o.PeekFront();
				getch();
				break;
			case 4:
				o.PeekRear();
				getch();
				break;
			case 5:
				cout << "Displaying the Queue : ";
				o.Display();
				getch();
				break;
			case 6:
				cout << "Program is Closed.";
				exit(1);
			default:
				cout << "Incorrect Choice.";
				getch();
				break;
		}
	}
}//end of main
