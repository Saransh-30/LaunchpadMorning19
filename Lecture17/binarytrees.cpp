#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* createTree()
{

	int d;
	cin>>d;

	if(d==-1)
	{
		return NULL;
	}

	node* root=new node(d);
	cout<<"enter left child of "<<d<<" : ";
	root->left=createTree();
	cout<<"enter right child of "<<d<<" : ";
	root->right=createTree();

	return root;

}

void preOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void inOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int leftChildHeight=height(root->left);
	int rightChildHeight=height(root->right);

	int h=max(leftChildHeight,rightChildHeight)+1;
	return h;
}

int count(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int leftCount=count(root->left);
	int rightCount=count(root->right);

	int totalCount=leftCount+rightCount+1;
	return totalCount;
}

int diameter(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	int op1=height(root->left)+height(root->right);
	int op2=diameter(root->left);
	int op3=diameter(root->right);

	int ans=max(op1,max(op2,op3));
	return ans;
}

class Pair
{
public:
	int Height;
	int Diameter;
};


Pair fastDiameter(node* root)
{
	Pair p;
	if(root==NULL)
	{
		p.Height=0;
		p.Diameter=0;
		return p;
	}

	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);

	p.Height=max(left.Height,right.Height)+1;

	int op1=left.Height+right.Height;
	int op2=left.Diameter;
	int op3=right.Diameter;

	p.Diameter=max(op1,max(op2,op3));

	return p;


}



int main()
{

	node *root=createTree();

	cout<<"preOrder traversal is  : ";
	preOrder(root);
	cout<<endl;
	cout<<endl;


	cout<<"postOrder traversal is : ";
	postOrder(root);
	cout<<endl;
	cout<<endl;


	cout<<"inOrder traversal is : ";
	inOrder(root);
	cout<<endl;
	cout<<endl;

	cout<<"height of tree is : ";
	cout<<height(root);
	cout<<endl;
	cout<<endl;


	cout<<"count of nodes are : ";
	cout<<count(root);
	cout<<endl;
	cout<<endl;

	Pair p=fastDiameter(root);
	cout<<"height using fastDiameter is "<<p.Height<<endl;
	cout<<"diameter using fastDiameter is "<<p.Diameter<<endl;

	return 0;
}














