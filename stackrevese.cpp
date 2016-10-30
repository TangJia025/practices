#include <iostream>
#include <stack>

using namespace std;

void ReverseStack(stack<int> &s);
int RemoveandGetLast(stack<int> &s);

int main()
{
	stack<int> s;
	for (int i = 1; i < 5; i++)
		s.push(i);
	ReverseStack(s);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	
	return 0;
}

void ReverseStack(stack<int> &s)
{
	if (s.empty()) return;
	int a = RemoveandGetLast(s);
	ReverseStack(s);
	s.push(a);
}

int RemoveandGetLast(stack<int> &s)
{
	int a = s.top();
	s.pop();
	if (s.empty()) return a;
	else
	{
		int b = RemoveandGetLast(s);
		s.push(a);
		return b;
	}
}

