#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


class VectorStack {
private:
	vector<int> container;
public:
	VectorStack();
	void printStack();
	void push(int& item);
	void pop();
	int& top();
	bool empty();
	int size();
	float average();

};