#include <iostream>

using namespace std;

class A
{
public:
	int b;
	int c;
	static A *p_a;
	A();
	static A *GetInstance();
};

A *A::p_a = NULL;
A::A()
{
	b = 2;
	c = 3;
}
A *A::GetInstance()
{
	if (p_a == NULL)
		p_a = new A();
	return p_a;
}

int main()
{
	A *p_a = A::GetInstance();
	cout << p_a->b << ", " << p_a->c << endl;
    delete p_a;

	return 0;
}

