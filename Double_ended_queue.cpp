//double ended queue(deque)

#include<iostream>
#include<conio.h>
using namespace std;
//1. Node templ
class DQNode{
	public:
		int data;
		DQNode *right;
		DQNode *left;
};
//2. Queue templ
class DQueue{
	DQNode *front;
	DQNode *rear;	
	public:
		DQueue(){
			front = NULL;
			rear = NULL;
		}	
		void EnqueueFront(int x);
		void EnqueueRear(int x);
		void DequeueFront();
		void DequeueRear();
		void PeekFront();
		void PeekRear();
		void Display();
		int Empty();
};

//3. functions
int DQueue::Empty() {
  if(front == NULL){
		return 1;
	}else
	{
		return 0;
	}
}
void DQueue::EnqueueFront(int x){

	//Make a new node
	DQNode *t=new DQNode();
	t->data=x;
	t->right=NULL;
	t->left=NULL;
	
	//First node in the DQNode
	if(front==NULL)
	{
		front=t;
		rear=t;
	}
	else
	{
		t->right=front;
		front->left=t;
		front=t;
	}
}
void DQueue :: EnqueueRear(int x)
{
	//Make a new node
	DQNode *t=new DQNode();
	t->data=x;
	t->right=NULL;
	t->left=NULL;
	
	//last node in the DeQueue 
	if(rear==NULL)
	{
		front=t;
		rear=t;
	}
	else
	{
		rear->right=t;
		t->left=rear;
		rear=t;
	}
	
}


void DQueue::DequeueFront(){
	if(Empty()){
		cout<<"Underflow!!";
		return;
	}
	DQNode *t=front;
	if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		front=front->right;
		front->left=NULL;
	}
	cout<<"Front element is dequeued!"<<endl;
	delete t;
	
	
}
void DQueue :: DequeueRear(){
	if(Empty())
	{
		cout<<"Underflow!!";
		return;
	}
	DQNode *t=front;
	if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		rear=rear->left;
		rear->right=NULL;
	}
	cout<<"Rear element is dequeued!"<<endl;
	delete t;	
}

void DQueue::Display(){
	if(Empty()){
		cout<<"Underflow!";
		return;
	}
	DQNode *t = front;
	while(t!=NULL){
		cout<<t->data<<"";
		t=t->right;
	}
	cout<<"Null";
}
//4. menu
int main(){ 
	DQueue d;
	int num,ch;
	
	while(1){
		system("cls");
		
		cout << "*****Double Ended Queue*****\n\n";
		
		cout<<"1. Enqueue Front.\n";
		cout<<"2. Enqueue Rear.\n";
		cout<<"3. Dequeue Front.\n";
		cout<<"4. Dequeue Rear.\n";
		cout<<"5. Peek Front\n";
		cout<<"6. Peek Rear.\n";
		cout<<"7. Display the queue.\n";
		cout<<"8. Exit\n";
		
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		
		switch(ch){
			case 1: cout <<"\nEnter a Number to insert : ";
					cin >> ch;
					d.EnqueueFront(num);
					getch();
					break;
			case 2:	cout <<"\nEnter a Number to insert : ";
					cin >> ch;
					d.EnqueueRear(num);
					getch();
					break;
			case 3:			
					getch();
					break;
			case 4:	
					getch();
					break;
			case 5:	
					getch();
					break;
			case 6:			
					getch();
					break;
			case 7:	
					getch();
					break;
			case 8: exit(1);
			default :
				cout << "Incorrect Choice";
				getch();
				break;
		}
	}
}
