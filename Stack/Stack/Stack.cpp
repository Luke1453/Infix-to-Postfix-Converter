#include "Stack.h"

using namespace std;


//Destructor for stack to automaticly destroy the array when object is killed
stack::~stack() {
	destroy();
}
stack::stack(int size) {

	create(size);

}
void stack::push(char ch) {

	if (isFull()) {

		cout << " Stack OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	//cout << "Pushed: " << ch << endl << endl;
	arr[++top] = ch;
}

char stack::pop() {

	// check for stack underflow
	if (isEmpty()) {

		cout << "Stack UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	//cout << "Removing: " << peek() << endl << endl;

	return arr[top--];
}

char stack::peek() {

	if (!isEmpty())
		return arr[top];
	else
		return NULL;
}

void stack::destroy() {

	delete arr;
	//cout << "stack was destroyed\n" << endl;
}

int stack::size() {
	return top + 1;
}

bool stack::isEmpty() {
	return top == -1;
}

bool stack::isFull() {
	return top == capacity - 1;
}
//creating stack
void stack::create(int size) {

	//cout << "stack was created\n" << endl;
	arr = new char[size];
	capacity = size;
	top = -1;
}
