#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class SimpleList
{
private:
	Node* _head, * _tail;

public:
	SimpleList()
	{
		_head = _tail = NULL;
	}
	virtual ~SimpleList();

	void QueueItem(int);
	int DequeueItem();
	void DisplayList();
	void Push(int);
	int Pop();
};

