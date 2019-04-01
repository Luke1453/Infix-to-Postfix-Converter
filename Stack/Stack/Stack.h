#pragma once

#include <iostream>

using namespace std;

// Class for stack
 class stack
{
	char *arr;
	int top;
	int capacity;

public:

	void destroy();
	~stack();
	
	void create(int size);	
	stack(int size);


	int size();
	bool isEmpty();
	bool isFull();

	void push(char ch);
	char pop();
	char peek();
	
	
};