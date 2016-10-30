#include <iostream>
#include <vector>

using namespace std;

class Buffer
{
public:
	int len;
	int *data;
	int front, rear;

	Buffer(int n)
	{
		len = n+1;
		front = rear = 0;
		data = new int[len];
	}

	void push(int i)
	{
		data[rear] = i;
		rear = (rear + 1) % len;
	}

	void pop()
    {
		data[front] = 0;
		front = (front + 1) % len;
	}

	bool empty()
	{
		return front == rear;
	}

	bool full()
	{
		return front == (rear + 1) % len;
	}
};

bool exist(Buffer *buff, int x)
{
	if (buff->empty()) return false;
	else if (buff->front > buff->rear)
	{
		for (int i = 0; i < buff->rear; i++)
		{
			if (buff->data[i] == x)
				return true;
		}
		for (int i = buff->front; i < buff->len; i++)
		{
			if (buff->data[i] == x)
				return true;
		}
		return false;
	}
    else
	{
		for (int i = buff->front; i < buff->rear; i++)
			if (buff->data[i] == x)
				return true;
		return false;
	}
}

int MissPage(int n, int *A, int m)
{
	Buffer *buff = new Buffer(n);
	int miss = 0;
	for (int i = 0; i < m; i++)
	{
		if (exist(buff, A[i]))
			continue;
		else
		{
			if (!buff->full())
				buff->push(A[i]);
			else
			{
				buff->pop();
				buff->push(A[i]);
			}
			miss++;
		}
	}
	return miss;
}           

int main()
{
	int n, m;
	int *A;
	cin >> n >> m;
	A = new int[m];
	for (int i = 0; i < m; i++)
		cin >> A[i];
	cout << "missed page : " << MissPage(n, A, m) << endl;

	delete A;

	return 0;
}



