#include <iostream>
#include "Queue.h"
#include <cassert>
using namespace std;


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
