#include <iostream>
#include <cassert>

using namespace std;

class Queue
{
public:
	Queue(int = 100);
	bool isEmpty();
	bool isFull();
	void addQueue(int);
	void deleteQueue();
	int front();
	int rear();
	void clearQueue();
	int getLength(){ return length; }
	int traverseQueue(int i)
	{
		return queue[i];
	}

	void pushMiddle(int x, int len)
	{
		queue[len / 2] = x;
	}
private:
	int maxSize, length, queueFront, queueRear, *queue;
};

Queue::Queue(int size)
{
	if (size <= 0)
		maxSize = 100;
	else
		maxSize = size;

	length = 0;
	queue = new int[maxSize];
	queueFront = 0;
	queueRear = maxSize - 1;
}

bool Queue::isEmpty()
{
	return (length == 0);
}

bool Queue::isFull()
{
	return (length == maxSize);
}

void Queue::deleteQueue()
{
	if (isEmpty())
		cout << "Empty Queue" << endl;
	else
	{
		queueFront = (queueFront + 1) % maxSize;
		length--;
	}
}
void Queue::addQueue(int item)
{
	if (isFull())
		cout << "Full Queue" << endl;
	else
	{
		queueRear = (queueRear + 1) % maxSize;
		queue[queueRear] = item;
		length++;
	}

}

int Queue::front()
{
	assert(!isEmpty());
	return queue[queueFront];
}

int Queue::rear()
{
	assert(!isEmpty());
	return queue[queueRear];
}

void Queue::clearQueue()
{
	length = 0;
	queueFront = 0;
	queueRear = maxSize - 1;
}

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

	/*Test Code
	int main()
	{
	cout << "Write your main() function to test ALL functions. "
	<< "We will run yuur code using YOUR AND OUR main()." << endl;
	return 0;
	}
	*/

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