#include <iostream>
#include <cctype>

using namespace std;

#ifndef NODE_
#define NODE_

long long int spelledCompares;      //keep track of total number of spelled corectly compares
long long int notSpelledCompares;   //keep track of total spelled incorrectly compares

template <class T>
class node {
public:
	T data;
	node <T>* next;
	node() { next = nullptr; }
	node(T item) {
		data = item;
		next = nullptr;
	}
};

template <class T>
class myList {
private:
	node<T>* head;
	int size = 0;
public:
	myList() : head(nullptr), size(0)
	{ }  //end constructor
	~myList();

	void insert(T item);
	void remove();
	//T front();
	void print();
	bool find(T item);
	bool isEmpty() {
		return size = 0;
	}
	int getSize() { return size; }
};

//destructor
template <class T>
myList<T>:: ~myList() {

	while (!isEmpty())
		remove();
}

template <class T>
void myList<T>::insert(T item) {

	node<T>* temp = new node<T>(item);

	(temp->next) = head;
	head = temp;

	//delete temp;
	size++;
}

//delete first
template <class T>
void myList<T>::remove() {
	node <T>* temp;

	if (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
	size--;
}

//print
template <class T>
void myList<T>::print() {
	for (node<T>* temp = head;
		temp != nullptr;
		temp = temp->next) {
		cout << temp->data;
		if (temp->next != nullptr) {
			cout << " -> ";
		}
		else {
			cout << " /\n";
		}
	}
}

//find function
template <class T>
bool myList<T>::find(T item) {
	long long int compares = 0;
	bool found;
	for (node<T>* temp = head; temp != nullptr; temp = temp->next) {
		if (temp->data.compare(item) == 0) {
			found = true;
			spelledCompares = spelledCompares + compares;
			return true;
		}
		compares = compares + 1;
	}
	if (!found) {
		notSpelledCompares = notSpelledCompares + compares;
	}
	//end of the list reached, so item is not in it
	return false;
}

#endif