#ifndef ERWL_h
#define ERWL_h
#include "Node.h"
using namespace std;

template<class T>
class ERWL
{
	//friend class Iterator;
public:
	ERWL();
	const bool isEmpty();
	void insertion(T newElement, int priority);
	T peek();
	void remove();
	void removeAll();
	int getSize();

private:
	Node<T>* front;
	Node<T>* rear;
	int size;
};
#endif

template<typename T>
ERWL<T>::ERWL()
{
	front = new Node<T>();
	rear = new Node<T>();
	this->front = nullptr;
	this->rear = nullptr;
	this->size = 0;
}

template<typename T>
const bool ERWL<T>::isEmpty()
{
	return (this->front == nullptr && this->rear == nullptr);
}

template<typename T>
void ERWL<T>::insertion(T newElement, int priority)
{
	Node<T>* newNode = new Node<T>(newElement, priority);
	if (this->isEmpty())
	{
		this->front = newNode;
		this->rear = newNode;
	}
	else
	{
		size++;
		Node<T>* temp = new Node<T>();
		temp = this->front->next;
		Node<T>* current = new Node<T>();
		current = this->front;
		while (temp->next != nullptr)
		{
			if (newNode->priority > current->priority)
			{
				this->front->next = this->front;
				this->front = newNode;
			}
			current = temp;
			temp = temp->next;
		}
	}
}

template<typename T>
void ERWL<T>::remove()
{
	if (this->isEmpty())
	{
		throw runtime_error("Queue is empty");
	}
	else
	{
		size--;
		Node<T>* temp = new Node<T>();
		temp = this->front;
		this->front = this->front->next;
		T element = temp->element;
		delete temp;
	}
}

template<typename T>
void ERWL<T>::removeAll()
{
	while (!this->isEmpty())
	{
		remove();
	}
}

template<typename T>
T ERWL<T>::peek()
{
	return this->front->element;
}

template<typename T>
int ERWL<T>::getSize()
{
	return this->size;
}
