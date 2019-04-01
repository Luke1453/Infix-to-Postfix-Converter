#include <iostream>
#include <string>

#include "Stack.h"

using namespace std;

void postfix();
bool association(char left, char right);

int main(){

	postfix();

	system("pause");
	return 0;
}

//functions---------------------------------------------------------------------------

bool association(char left,char right) {
	if (((left == '+' || left == '-') && (right == '+' || right == '-')) || ((left == '*' || left == '/') && (right == '*' || right == '/'))) {
		return true;
	}
	else {
		return false;
	}
		
}

void postfix() {

	system("cls");

	cout << "Infix notation to postfix(reverse polish) notation using stack \"shunting yard algorithm.\"" << endl; //cout is ambigous???
	cout << "!WARNING!: valid symbols: A-Z a-z 0-9 ( ) / * - +" << endl<<endl;

	cout << "Please enter the equation: ";
	string str_equation;
	cin >> str_equation;
	const char* arrc_equation = str_equation.c_str();
	int i_equation_lenght = str_equation.length();

	stack *c_S = new stack(100);
	//queue *c_Q = new queue(100);

	char arrc_posfix[200];
	int i_posfix_lastop = 0;

	for (int i = 0; i < i_equation_lenght; i++) {

		if (((int)arrc_equation[i] >= 48 && (int)arrc_equation[i] <= 57) || ((int)arrc_equation[i] >= 65 && (int)arrc_equation[i] <= 90) || ((int)arrc_equation[i] >= 97 && (int)arrc_equation[i] <= 122)) {	//numbers

			arrc_posfix[i_posfix_lastop] = arrc_equation[i]; //pushing numbers to stack
			i_posfix_lastop++;

		}
		else {	//parenthesis

			if (arrc_equation[i] == '(') {

				c_S->push(arrc_equation[i]);	//Pushing ( to stack
			}
			else if (arrc_equation[i] == ')') {

				while (c_S->peek() != '(') {

					arrc_posfix[i_posfix_lastop] = c_S->pop();	//printong everything till the (
					i_posfix_lastop++;
				}

				c_S->pop();	//removing (
			}
			else {	//symbols

				if (c_S->isEmpty() == true || c_S->peek() == '(') {

					c_S->push(arrc_equation[i]);
				}
				else {	//deating with precedance

					if ((arrc_equation[i] == '/' || arrc_equation[i] == '*') && (c_S->peek() == '+' || c_S->peek() == '-')) {	//i dont have right associative operators in here

						c_S->push(arrc_equation[i]);
					}
					else if (((arrc_equation[i] == '+' || arrc_equation[i] == '-') && (c_S->peek() == '*' || c_S->peek() == '/')) || (association(arrc_equation[i], c_S->peek()))){	//first part is precedance second is left associative operators eg. 1-2+3=(1-2)+3

						do {

							arrc_posfix[i_posfix_lastop] = c_S->pop();	//printing everything till the ( or + or -
							i_posfix_lastop++;

							if (c_S->isEmpty() == true)break;

						} while (!c_S->isEmpty() || c_S->peek() != 0 || c_S->peek() != '+' || c_S->peek() != '-' || c_S->peek() != '('); //wtf is this shit if i remove break();

						c_S->push(arrc_equation[i]);
					}
					
				}
			}

		}

	}

	while (c_S->isEmpty() != true) {

		arrc_posfix[i_posfix_lastop] = c_S->pop();	//printing chars left in stack
		i_posfix_lastop++;
	}
	string s_posfix(arrc_posfix);
	s_posfix.erase(i_posfix_lastop);
	cout << "Posfix notation: "+s_posfix << endl;
    
	delete c_S;
	//system("PAUSE");
}