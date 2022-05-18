#include <iostream>
#include <string>

using namespace std;

typedef struct Node NODE;
struct Node
{
    char data;
    int index;
    NODE* next;
};
typedef struct Stack STACK;
struct Stack
{
    NODE* top;
};

void CreateStack(STACK&);
void Push(STACK&, char, int);
Node* Pop(STACK&);
Node* Top(STACK);
bool IsFull(STACK);
bool IsEmpty(STACK);
void ReadData(string&, int&);
void Solve(string, int);

int main() {
    STACK st;
    string s;
    int n;
    ReadData(s, n);
    Solve(s, n);
    return 0;
}

void CreateStack(STACK& st)
{
    st.top = nullptr;
}
void Push(STACK& st, char x, int index)
{
    NODE* t = new NODE;
    if (t == nullptr)
        cout << "Stack Overflow!" << endl;
    else
    {
        t->data = x;
        t->index = index;
        t->next = st.top;
        st.top = t;
    }
}
Node* Pop(STACK& st)
{
    Node* temp = nullptr;
    if (st.top == NULL)
    {
        cout << "Stack Underflow!" << endl;
        return nullptr;
    }
    else
    {
        NODE* p = st.top;
        st.top = st.top->next;
        temp = new Node;
        temp->data = p->data;
        temp->index = p->index;
        temp->next = nullptr;
        delete p;
    }
    return temp;
}
Node* Top(STACK st)
{
    Node* temp = nullptr;
    if (st.top == NULL)
        cout << "Empty Stack!" << endl;
    else
    {
        temp = new Node;
        temp->data = st.top->data;
        temp->index = st.top->index;
        temp->next = nullptr;
    }
    return temp;
}
bool IsFull(STACK st)
{
    NODE* t = new NODE;
    bool r = (t == nullptr) ? true : false;
    delete t;
    return r;
}
bool IsEmpty(STACK st)
{
    if (st.top == nullptr)
        return true;
    return false;
}
void ReadData(string& s, int& n)
{
    getline(cin, s);
    n = s.length();
}
void Solve(string s, int n)
{
    STACK st;
    Node* temp = nullptr;
    CreateStack(st);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            Push(st, s[i], i);
        else
        {
            temp = Pop(st);
            cout << temp->index + 1 << " " << i + 1 << endl;
        }
    }
}