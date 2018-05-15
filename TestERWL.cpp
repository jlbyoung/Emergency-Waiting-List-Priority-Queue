#include<iostream>
#include<cstring>
using namespace std;

#include "ERWL.h"

template<typename T>
void printList(ERWL<T>& T);

int main()
{
	ERWL<string>* list = new ERWL<string>();
	list->insertion("Nick", 5);

	list->remove();
	printList(*list);
	cout << endl;

	system("pause");
	return 0;

}

template<typename T>
void printList(ERWL<T>& myList)
{
	if (myList.isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node<T> temp = new Node<T>();
		temp = myList->front;
		while (temp->next != nullptr)
		{
			cout << temp->element << " " << temp->priority << ":";
		}
		cout << endl;
	}
}

