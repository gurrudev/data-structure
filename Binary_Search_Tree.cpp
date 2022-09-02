
#include<iostream>
#include<conio.h>

using namespace std;

//1.NODE TEMPLATE
class BSTNode
{
	public:
			int data;
			BSTNode *right;
			BSTNode *left;
};
//2.CLASS TEMPLATE
class BST
{
	BSTNode *root;
	int cnt;
	
	public:
			BST()
			{
				root = NULL;
				cnt = 0;
			}
			void Insert(int x);
			void Display();
			void FindMin();
			void FindMax();
			void CountNodes();	
			void PreOrder(BSTNode *t);
			void PostOrder(BSTNode *t);
			void InOrder(BSTNode *t);
};

//3.Functions
void BST :: Insert(int x)
{
	BSTNode *t = new BSTNode();
	
	t->data = x;
	t->right = NULL;
	t->left = NULL;
	
	if(root == NULL)
	{
		root = t;
		return;		
	}
	BSTNode *tmp = root;
	BSTNode *prev = NULL;
	
	while(tmp!=NULL)
	{
		prev = tmp;
		
		if(t->data > tmp->data)
		{
			tmp = tmp->right;
		}
		else if(t->data < tmp->data)
		{
			tmp = tmp->left;
		}
		else
		{
			cout << "Duplicate elements are not allowed!";
			getch();
			return;
		}
	}//end of while
	if(t->data > prev->data)
	{
		prev->right = t;
	}
	else
	{
		prev->left = t;
	}
	cnt++;
}//end of insert

void BST :: FindMin()
{
	if(root == NULL)
	{
		cout << "EMPTY TREE!!";
		return;
	}
	BSTNode *tmp = root;
	BSTNode *prev = NULL;
	
	while(tmp!=NULL)
	{
		prev = tmp;
		tmp = tmp->left;
	}
	
	cout << "Minimum Element in the tree is : " << prev->data;
}//end of find min

void BST :: FindMax()
{
	if(root == NULL)
	{
		cout << "EMPTY TREE!!";
		return;
	}
	BSTNode *tmp = root;
	BSTNode *prev = NULL;
	
	while(tmp!=NULL)
	{
		prev = tmp;
		tmp = tmp->right;
	}
	
	cout << "Maximum Element in the tree is : " << prev->data;
}//end of find max

void BST :: CountNodes()
{
	if(root == NULL)
	{
		cout << "EMPTY TREE!!";
		return;
	}
	
	cout << "Number of the elements in the tree is : " << cnt;
}//end of count

void PreOrder(BSTNode *t)
{
	if(t)
	{
		cout << t->data;
		PreOrder(t->left);
		PreOrder(t->right);
	}
}//end of preorder
void PostOrder(BSTNode *t)
{
	if(t)
	{
		PostOrder(t->left);
		PostOrder(t->right);
		cout << t->data;
	}
}//end of postorder
void InOrder(BSTNode *t)
{
	if(t)
	{
		InOrder(t->left);
		cout << t->data;
		InOrder(t->right);
	}
}//end of inorder

void BST :: Display()
{
	if(root == NULL)
	{
		cout << "Empty Tree";
		return;
	}
	cout << "PreOrder Traversal : " << PreOrder(root);
	cout << endl;
	cout << "PostOrder Traversal : " << PostOrder(root);
	cout << endl;
	cout << "InOrder Traversal : " << InOrder(root);
	cout << endl;
}
//4.MENU

int main()
{
	BST b;
	int num,ch;
	while(1)
	{
		system("cls");
		cout << "*****Binary Search tree*****";
		
		cout << "1.Insert and Element\n";
		cout << "2.Display the tree\n";
		cout << "3.Find the Minimum element\n";
		cout << "4.Find the Maximum element\n";
		cout << "5.Count the Number of the Nodes\n";
		cout << "6.EXIT\n";
	
	
		cout << "Enter your choice : ";
		cin >> ch;
		
		switch(ch)
		{
			case 1 : 
				cout << "Enter an element";
				cin >> num;
				b.Insert(num);
				getch();
				break;
			case 2 : 
				cout << "Displaying the tree : ";
				b.Display();
				getch();
				break;
			case 3 : 
				b.FindMin();
				getch();
				break;
			case 4 : 
				b.FindMax();
				getch();
				break;
			case 5: 
				b.CountNodes();
				getch();
				break;
			case 6 : 
				exit(1);
			default : 
				cout << "Incorrect Choice!";
				getch();
		}
	}			
}
