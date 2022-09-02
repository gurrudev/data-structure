
#include<iostream>
#include<conio.h>

#define MAX 4

using namespace std;

//1.Node Template
//2.class Template
class CQueue
{
	int A[MAX];
	int front;
	int rear;
	int cnt;
	
	public:
			CQueue()
			{
				front = -1;
				rear = -1;
				cnt = 0;
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
void CQueue :: Enqueue(int x)
{
	if(Full())
	{
		cout << "Queue Overflow\n";
		return;
	}
	if(Empty())
	{
		front++;
	}
	if(rear == MAX-1)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}
	A[rear] = x;
	cnt++;
}//end of enqueue
int CQueue :: Full()
{
	if(cnt == MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//end of full
int CQueue :: Empty()
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

void CQueue :: PeekFront()
{
	if(Empty())
	{
		cout<<"Queue is Empty.";
		return;
	}
	
	cout<<"Element at the front is : " << A[front];
}//end of peekfront

void CQueue::PeekRear()
{
	if(Empty())
	{
		cout << "Queue is Empty.";
		return;
	}
	
	cout << "Element is at the rear is : " << A[rear];
}//end of rear

void CQueue :: Dequeue()
{
	
	if(Empty())
	{
		cout << "Queue is Empty!";
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
		if(front == MAX-1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
	}
	cout << "Element deleted is : " << tmp;
	cnt--;
	
}//end of dequeue

void CQueue :: Display()
{
	if(Empty())
	{
		cout << "Queue is Empty!";
		return;
	}
	
	int j = front;
	for(int i=1 ; i<=cnt ; i++)
	{
		cout << A[j] << " ";
		if(j == MAX-1)
		{
			j=0;
		}
		else
		{
			j++;
		}
	}
}//end of display

//4.Menu

int main()
{
	CQueue c;
	int num,ch;
	
	while(1)
	{
		system("cls");
		
		cout << "*****Circular Queues*****\n";
		
		cout << "1.Enqueue an Element\n";
		cout << "2.Dequeue an Element\n";
		cout << "3.Peek at the front in Qeuue\n";
		cout << "4.Peek at the rear in Queue\n";
		cout << "5.Display the Queue\n";
		cout << "6.Exit\n\n";
		
		cout << "Enter Your Choice : ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter an element : ";
				cin >> num;
				c.Enqueue(num);
				getch();
				break;
			case 2:
				c.Dequeue();
				getch();
				break;
			case 3:
				c.PeekFront();
				getch();
				break;
			case 4:
				c.PeekRear();
				getch();
				break;
			case 5:
				cout << "Displaying the Queue : ";
				c.Display();
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
}//end of menu
