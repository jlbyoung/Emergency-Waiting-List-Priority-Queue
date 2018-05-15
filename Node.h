#ifndef Node_h
#define Node_h
using namespace std;

template<typename T>
class Node
{
public:
	int priority;
	T element;
	Node<T>* next;
	Node()
	{
		next = nullptr;
	}
	Node(T element, int priority)
	{
		this->element = element;
		next = nullptr;
		this->priority = priority;
	}
}; 

#endif