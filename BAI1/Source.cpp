#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct List
{
	Node* head;
	Node* tail;
};

Node* InitNode(int x);
void InitList(List&);
void Insert(List&, int);
void Insert(List&, Node*);
void QuickSort(List&);
void Delete(List&, int);
void PrintList(List);
void ReadData(List&, int&);

int main()
{
	int n{ 0 };
	List l;
	InitList(l);
	ReadData(l, n);
	cout << "List ban dau: " << endl;
	PrintList(l);

	QuickSort(l);
	cout << "\nList sau khi sap xep tang dan: " << endl;
	PrintList(l);

	Delete(l, 2);
	cout << "\nList sau khi xoa 2: " << endl;
	PrintList(l);

	return 0;
}

Node* InitNode(int x)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->data = x;
	p->next = nullptr;
	return p;
}
void InitList(List& l)
{
	l.head = l.tail = nullptr;
}
void Insert(List& l, int x)
{
	Node* p;
	p = InitNode(x);
	if (p == nullptr)
	{
		cout << "List is full" << endl;
		exit(-1);
	}
	else
	{
		if (l.tail == nullptr)
			l.head = l.tail = p;
		else
		{
			l.tail->next = p;
			l.tail = p;
		}
	}
}
void Insert(List& l, Node* p)
{
	if (l.tail == nullptr)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
		p->next = nullptr;
	}
}
void QuickSort(List& l)
{
	Node* p, * m;
	List l1, l2;
	
	if (l.head == l.tail) return;

	InitList(l1);
	InitList(l2);

	m = l.head;
	l.head = l.head->next;

	while (l.head != nullptr)
	{
		p = l.head;
		l.head = l.head->next;
		p->next = nullptr;
		if (p->data < m->data)
			Insert(l1, p);
		else
			Insert(l2, p);
	}

	QuickSort(l1);
	QuickSort(l2);

	if (l1.head != nullptr)
	{
		l.head = l1.head;
		l1.tail->next = m;
	}
	else
		l.head = m;
	m->next = l2.head;
	if (l2.head != nullptr)
		l.tail = l2.tail;
	else
		l.tail = m;
}
void Delete(List& l, int x)
{
	if (l.head == nullptr)
	{
		cout << "Day khong co so can xoa" << endl;
		return;
	}
	else
	{
		bool flag = false;
		Node* q = nullptr;
		Node* p = l.head;
		while (p != nullptr)
		{
			if (p->data == x)
			{
				flag = true;
				if (p == l.head)
				{
					l.head = l.head->next;
					delete p;
					p = l.head;
				}
				else
				{
					q->next = p->next;
					delete p;
					p = q->next;
				}
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
		if (flag == false)
			cout << "Day khong co so can xoa" << endl;
		else
			l.tail = q;
	}
}
void PrintList(List l)
{
	Node* p = l.head;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void ReadData(List& l, int& n)
{
	int x{ 0 };
	Node* p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		p = InitNode(x);
		if (p == nullptr)
		{
			cout << "List is full" << endl;
			exit(-1);
		}
		Insert(l, p);
	}
}