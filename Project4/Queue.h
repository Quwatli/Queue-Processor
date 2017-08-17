#pragma once

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
	int getLength() { return length; }
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

