#include "VectorStack.h";


VectorStack::VectorStack() {
}


void VectorStack::push(int& item) {
	container.push_back(item);
}


void VectorStack::pop() {
	container.pop_back(); 
}

int& VectorStack::top() {
	return container.back(); 
}


bool VectorStack::empty() {
	return container.empty();
}


int VectorStack::size() {
	return container.size();
}

void VectorStack::printStack() {
	for (int x = 0; x < size(); x++) {
		cout << container[x] << endl;
	}
}