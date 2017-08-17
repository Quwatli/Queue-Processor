#include <iostream>
#include <cassert>
#include "Queue.h"

using namespace std;

void copyQueue(Queue &q1, Queue &q2)
{
	if (!q2.isEmpty())
	{
		cout << "q2 should be empty, q2 will be cleared.\n";
		q2.clearQueue();
	}
	else
	{
		while (!q1.isEmpty())
		{
			q2.addQueue(q1.front());
			q1.deleteQueue();
		}
		cout << endl;
		while (!q2.isEmpty())
		{
			q1.addQueue(q2.front());
			q2.deleteQueue();
		}
	}
}

void countGreater(int x, Queue q1)
{
	int count = 0;
	for (int i = 0; i < q1.getLength(); i++)
		if (q1.traverseQueue(i)>x)
			count++;
	cout << count << " elements greater than " << x << endl;
}

void findMax(Queue q1)
{
	int max = 0;
	for (int i = 0; i < q1.getLength(); i++)
		if (q1.traverseQueue(i)>max)
			max = q1.traverseQueue(i);
	cout << "\nThe maximum value in your queue is " << max << endl;
}

void insertMiddle(int c, Queue q1)
{
	//calculating the lenght
	int length = 0;
	for (int i = 0; i <= q1.getLength(); i++)
		if (q1.traverseQueue(i)>0)
			length++;
	q1.pushMiddle(c, length);

}


void main()
{

	Queue q1(10), q2(10);
	int z, x;
	cout << "\nFill in queue with 10 integer values:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> z;
		q1.addQueue(z);
	}

	cout << "\nQueue q1 before copying q2:" << endl;
	for (int i = 0; i < q1.getLength(); i++)
		cout << q1.traverseQueue(i) << " ";
	cout << endl;

	copyQueue(q1, q2);

	cout << "\nQueue q2 after copy:" << endl;
	for (int i = 0; i < q1.getLength(); i++)
		cout << q2.traverseQueue(i) << " ";
	cout << endl;

	cout << "\nQueue q1 after copying q2:" << endl;
	for (int i = 0; i < q1.getLength(); i++)
		cout << q1.traverseQueue(i) << " ";
	cout << endl;

	cout << "\nEnter an integer to search for greater values in Queue q1:" << endl;
	cin >> x;
	countGreater(x, q1);

	findMax(q1);

	cout << "\nEnter an integer to insert in the middle of the queue q1:" << endl;
	cin >> x;
	insertMiddle(x, q1);

	for (int i = 0; i < q1.getLength(); i++)
	{
		cout << q1.traverseQueue(i) << " ";
	}
	cout << endl;

	char c;
	cout << "\nWritten by Abdul Rahman Zahir Quwatli\n" << "enter any key to continue\n";
	cin >> c;
}



