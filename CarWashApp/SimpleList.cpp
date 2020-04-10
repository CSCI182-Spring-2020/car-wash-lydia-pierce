#include <iostream>
#include "SimpleList.h"
#include "Node.h"

using namespace std;

struct EmptyListException : public exception {
	const char* what() const throw() {
		return "Error: the queue is empty.";
	}
};

/// <summary>
/// Destructor
/// </summary>
SimpleList::~SimpleList()
{
	Node* temp;
	while (_head != NULL)
	{
		temp = _head;
		_head = temp->next;
		delete temp;
	}
}

void SimpleList::QueueItem(int newValue)
{
	Node* temp = new Node;
	temp->value = newValue;
	temp->next = NULL;

	if (_head == NULL) // Empty List
	{
		_head = _tail = temp;
	}
	else // Full
	{
		_tail->next = temp;
		_tail = temp;
	}

	//cout << "Queued Item" << endl;
}

int SimpleList::DequeueItem()
{
	// Is empty?
	if (_head == NULL)
		throw EmptyListException();

	Node* temp = _head;
	_head = temp->next;

	// Set the new head to maintain the list
	// even if the next item is NULL (empty)
	if (_head == NULL)
		_tail == NULL;

	int nReturn = temp->value;

	//cout << "Dequeued node" << endl;
	return nReturn;
}

void SimpleList::DisplayList()
{
	if (_head == NULL)
		throw EmptyListException();;
	Node* temp;
	temp = _head;
	while (1)
	{
		cout << temp->value << endl;
		if (temp == _tail)
			return;
		temp = temp->next;
	}
}

void SimpleList::Push(int value)
{
	Node* temp = new Node;
	temp->value = value;
	temp->next = _head;
	if (_head == NULL) // Empty List
		_head = _tail = temp;
	else
		_head->next = temp;
	_head = temp;

	cout << "Pushed Item" << endl;
}

int SimpleList::Pop()
{
	// Is empty?
	if (_head == NULL)
		throw EmptyListException();

	Node* temp = _head;
	_head = temp->next;


	_head = temp->next;

	// Set the new head to maintain the list
	// even if the next item is NULL (empty)
	if (_head == NULL)
		_tail == NULL;

	int nReturn = temp->value;

	cout << "Popped Item" << endl;
	return nReturn;
}