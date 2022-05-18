#include <iostream>
#include <math.h>
using namespace std;

struct TNode
{
	int data;
	TNode* left;
	TNode* right;
};

struct BST
{
	TNode* root;
};

TNode* InitTNode(int);
void InitBST(BST&);
void Insert(BST&, int);
void PrintNLR(TNode*);
int Height(TNode*);
TNode* CommonRoot(TNode*, int, int);
int DistanceFromRoot(TNode*, int);
int Distance(TNode*, int, int);
void ReadData(BST&, int&);

int main()
{
	int x, y;
	int n;
	BST t;
	InitBST(t);
	//ReadData(t, n);
	t.root = InitTNode(5);
	t.root->left = InitTNode(4);
	t.root->right = InitTNode(7);
	t.root->left->left = InitTNode(3);
	t.root->right->left = InitTNode(6);
	t.root->right->right = InitTNode(9);
	cout << "Cay ban dau: " << endl;
	PrintNLR(t.root);
	
	cout << "\nChieu cao cua cay: " << Height(t.root) << endl;

	cin >> x >> y;
	cout << "\nKhoang cach tu " << x << " " << y << " la: " << Distance(t.root, x, y) << endl;
}

TNode* InitTNode(int x)
{
	TNode* p = new TNode;
	if (p == nullptr)
		return nullptr;
	p->data = x;
	p->left = p->right = nullptr;
	return p;
}
void InitBST(BST& t)
{
	t.root = nullptr;
}
void Insert(BST& t, int x)
{
	TNode* p = InitTNode(x);
	if (p == nullptr)
	{
		cout << "Tree is full" << endl;
		exit(-1);
	}
	else
	{
		TNode* pre, * cur;
		pre = nullptr;
		cur = t.root;
		while (cur != nullptr)
		{
			pre = cur;
			if (x < cur->data)
				cur = cur->left;
			else if (x > cur->data)
				cur = cur->right;
			else
			{
				cout << "\nValue existed" << endl;
				exit(-1);
			}
		}
		if (x < pre->data)
			pre->left = p;
		else
			pre->right = p;
	}
}
void PrintNLR(TNode* root)
{
	if (root == nullptr)
		return;
	else
	{
		cout << root->data << " ";
		PrintNLR(root->left);
		PrintNLR(root->right);
	}
}
int Height(TNode* root)
{
	if (root == nullptr)
		return 0;
	else
	{
		int x = 0, y = 0;
		x = Height(root->left);
		y = Height(root->right);
		return x > y ? x + 1 : y + 1;
	}
}
TNode* CommonRoot(TNode* root, int x, int y)
{
	if (root == nullptr)
		return nullptr;
	if (x <= root->data && y >= root->data)
		return root;
	TNode* l = CommonRoot(root->left, x, y);
	TNode* r = CommonRoot(root->right, x, y);
	return l ? l : r;
}
int DistanceFromRoot(TNode* root, int x)
{
	TNode* p = root;
	int d = 0;
	if (root->data == x)
		return 0;
	while (p->data != x) 
	{
		if (x < p->data)
			p = p->left;
		else if (x > p->data)
			p = p->right;
		 d++;
	}
	return x < root->data ? d : -d;
}
int Distance(TNode* root, int x, int y)
{
	int a, b;
	if (x < y) { a = x; b = y; }
	else { a = y; b = x; }
	TNode* parentTNode = CommonRoot(root, a, b);
	int dx = DistanceFromRoot(parentTNode, x);
	int dy = DistanceFromRoot(parentTNode, y);
	return abs(dx - dy);
}
void ReadData(BST& t, int& n)
{
	int x;
	TNode* p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		x = rand() % 100;
		Insert(t, x);
	}
}