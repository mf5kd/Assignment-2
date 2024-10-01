#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Node {
	string data;
	Node* nextPtr;
	int ID;
};

class SingleLinkList {
private:
	Node* headPtr;
	Node* tailPtr;
	int NumOfIndexs = -1;
public:
	SingleLinkList();
	SingleLinkList(string d);
	SingleLinkList(vector<string> d);
	Node* front();
	Node* back();
	bool empty();
	void push_front(string d);
	void push_back(string d);
	bool pop_back();
	bool pop_front();
	void insert(int id, string d);
	bool remove(int id);
	int find(string d);
	int size();
	void printNode(int id);
	void printList();
};
