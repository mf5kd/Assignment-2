#include "SingleLinkList.h"

SingleLinkList::SingleLinkList() {
    headPtr = nullptr;
    tailPtr = nullptr;
}
SingleLinkList::SingleLinkList(string d) {
    Node* tempPtr = new Node;
    tempPtr->data = d;
    tempPtr->nextPtr = nullptr;
    tempPtr->ID = NumOfIndexs + 1;
    headPtr = tempPtr;
    tailPtr = tempPtr;
    NumOfIndexs++;
}
SingleLinkList::SingleLinkList(vector<string> d) {
    headPtr = nullptr;
    tailPtr = nullptr;
    for (int i = 0; i < d.size(); i++) {
        push_back(d[i]);
    }
}

Node* SingleLinkList::front() {
    return headPtr;
}

Node* SingleLinkList::back() {
    return tailPtr;
}

bool SingleLinkList::empty() {
    if (headPtr == nullptr) {
        return true;
    }
    return false;
}

int SingleLinkList::size() {
    return NumOfIndexs + 1;
}

int SingleLinkList::find(string d) {

    Node* tempPtr = headPtr;
    while (tempPtr->data != d) {
        if (tempPtr == nullptr) {
            return size();
        }
        tempPtr = tempPtr->nextPtr;
    }

    return tempPtr->ID;
}

void SingleLinkList::printNode(int id) {
    Node* tempPtr = headPtr;
    while (tempPtr->ID != id) {
        tempPtr = tempPtr->nextPtr;
    }
    cout << tempPtr->data << " -> " << tempPtr->nextPtr->data;
}

void SingleLinkList::push_back(string d) {
    // create a new node and putting in the data
    Node* newNode = new Node;
    newNode->data = d;
    newNode->nextPtr = nullptr;
    newNode->ID = NumOfIndexs + 1;

    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    }

    else {
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr && tempPtr->nextPtr != nullptr) {
            tempPtr = tempPtr->nextPtr;
        }
        //adjust the pointers
        newNode->nextPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
    NumOfIndexs++;
}

void SingleLinkList::push_front(string d) {
    // create a new node and putting in the data
    Node* newNode = new Node;
    newNode->data = d;
    newNode->nextPtr = nullptr;
    newNode->ID = -1;

    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    }
    else {
        Node* tempPtr = headPtr;
        //adjust the pointers
        newNode->nextPtr = tempPtr;
        headPtr = newNode;
    }
    NumOfIndexs++;
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        tempPtr->ID++;
        tempPtr = tempPtr->nextPtr;
    }
}

bool SingleLinkList::pop_back() {
    if (headPtr == nullptr) {
        return false;
    }
    Node* delNode = tailPtr;
    Node* tempPtr = headPtr;
    while (tempPtr->nextPtr != tailPtr) {
        tempPtr = tempPtr->nextPtr;
    }
    tailPtr = tempPtr;
    tempPtr->nextPtr = nullptr;
    delete delNode;
    delNode = nullptr;
    NumOfIndexs--;
    return true;
}

bool SingleLinkList::pop_front() {
    if (headPtr == nullptr) {
        return false;
    }
    Node* delNode = headPtr;
    headPtr = headPtr->nextPtr;
    delete delNode;
    delNode = nullptr;
    NumOfIndexs--;
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        tempPtr->ID--;
        tempPtr = tempPtr->nextPtr;
    }
    return true;
}

void SingleLinkList::insert(int id, string d) {
    if (headPtr == nullptr) {
        push_back(d);
        return;
    }

    Node* tempPtr = headPtr;
    while (tempPtr->ID != id-1) {
        tempPtr = tempPtr->nextPtr;
    }

    Node* newNode = new Node;
    newNode->data = d;
    newNode->nextPtr = tempPtr->nextPtr;
    newNode->ID = id;
    tempPtr->nextPtr = newNode;

    tempPtr = tempPtr->nextPtr->nextPtr;
    while (tempPtr != nullptr) {
        tempPtr->ID++;
        tempPtr = tempPtr->nextPtr;
    }
    NumOfIndexs++;

}

bool SingleLinkList::remove(int id) {
    if (headPtr == nullptr) {
        return false;
    }

    if (id > NumOfIndexs) { return false; }

    if (headPtr->ID == id) {
        Node* delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        NumOfIndexs--;
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            tempPtr->ID--;
            tempPtr = tempPtr->nextPtr;
        }
        return true;
    }

    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        if (tempPtr->nextPtr->ID == id) {
            if (id == NumOfIndexs){
                tailPtr = tempPtr;
            }
            Node* delNode = tempPtr->nextPtr;
            tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
            delete delNode;
            delNode = nullptr;
            NumOfIndexs--;
            tempPtr = tempPtr->nextPtr;
            while (tempPtr != nullptr) {
                tempPtr->ID--;
                tempPtr = tempPtr->nextPtr;
            }
            return true;
        }
        tempPtr = tempPtr->nextPtr;
    }
    return false;
}




void SingleLinkList::printList() {
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        cout << "(" + tempPtr->data + ", " << tempPtr->ID << ") -> ";
        tempPtr = tempPtr->nextPtr;
    }
    cout << "null" << endl;
}