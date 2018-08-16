//////////////////
//Hanna Sasina
///////////////////

#include<iostream>
// Reads from a file
#include<fstream>
// Reads from a string
#include <sstream>
#include<string>
#include<cstdlib>
#include "llStack.h"

using namespace std;

// check if coming string is an operator
bool isOperator(const string& input) {
	string operators[] = { "-", "+", "*", "/" };
	for (int i = 0; i < 4; i++) {
		if (input == operators[i]) {
			return true;
		}
	}
	return false;
}
// perform calculations on the stack
bool calculateStack(const string& input, LLStack<int>& stack) {
	if (stack.size() < 2) {
		return false;
	}
	int rVal, lVal, result;

	// pop the values from the stack
	rVal = stack.top();
	stack.pop();

	lVal = stack.top();
	stack.pop();

	// check what operator is given and calculate
	if (input == "-") {
		result = lVal - rVal;
	} else if (input == "+") {
		result = lVal + rVal;
	} else if (input == "*") {
		result = lVal * rVal;
	} else {
		result = lVal / rVal;
	}
	// push the result back to the stack
	stack.push(result);
	return true;
}

void calculate(const string& input) {
	LLStack<int> stack;
	// Create a string stream from the input string
	istringstream iss(input);
	// Split on whitespace
	for (string s; iss >> s;) {
		// if it is not an operator, convert string to int and push it to the stack
		if (!isOperator(s)) {
			int value = atoi(s.c_str());
			stack.push(value);
			// if it is an operator, check for input errors, make computations and print the result
		} else {
			// if operator is coming and the stack is empty or has only one element, print error
			if (!calculateStack(s, stack)) {
				cout << "INPUT ERROR" << endl;
				return;
			}
		}
	}
	// if after all computations stack has more than one element, print error
	if (stack.size() != 1) {
		cout << "INPUT ERROR" << endl;
		return;
	}
	cout << stack.top() << endl;
}

//argc = argument count, arvc = argument vector - array of character pointers
int main(int argc, char ** argv) {
	string input;
	// Only invocation call is in the array, no file name
	if (argc == 1) {
		getline(cin, input);
	} else {
		//Arguments on command line
		// argc == 2, first element is invocation call, second is a file name
		// open file, read input and make calculations
		ifstream file(argv[1]);
		if (file.is_open() && file.good()) {
			getline(file, input);
			file.close();
		} else {
			exit(EXIT_FAILURE);
		}
	}
	calculate(input);
	return 0;
}

