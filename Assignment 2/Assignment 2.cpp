// Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "SingleLinkList.h"
#include "VectorStack.h"

using namespace std;

int main()
{
    int c = 0;
    vector<string> fileData;
    // Open input file and check if there is an error 
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    while (fin.good()) {
        fileData.resize(c + 1);
        fin >> fileData[c];
        c++;
    }
    fin.close();

    SingleLinkList SList(fileData);
    VectorStack VStack;

    cout << "Single Link List\n";
    cout << "-----------------\n";
    cout << "\nFRONT OF LIST\n";
    cout << SList.front()->data << endl;
    cout << "\nBACK OF LIST\n";
    cout << SList.back()->data << endl;
    cout << "\nSIZE OF LIST\n";
    cout << SList.size() << endl;
    cout << "\nTHE WHOLE LIST WITH INDEXES\n";
    SList.printList();
    cout << "\nINSERTS 'MIGUEL' AT INDEX 5\n";
    SList.insert(5, "MIGUEL");
    SList.printList();
    cout << "\nREMOVES NODE AT INDEX 8\n";
    SList.remove(8);
    SList.printList();
    cout << "\nFINDS 'X' IN LIST\n";
    cout << "'X' is at index: " << SList.find("X") << endl;
   
    
    cout << "\nVector Stack\n";
    cout << "-----------------\n";
    cout << "\nTHE WHOLE STACK\n";
    for (int x = 1; x <= 20; x++) {
        VStack.push(x);
    }
    VStack.printStack();
    cout << "\nCHECK IF STACK IS EMPTY\n";
    bool b = VStack.empty();
    if (b == 0)
        cout << "FALSE" << endl;
    else
        cout << "TRUE" << endl;
    cout << "\nADD TO TOP OF STACK\n";
    int num = 81;
    VStack.push(num);
    VStack.printStack();
    cout << "\nREMOVE FROM TOP OF STACK\n";
    VStack.pop();
    VStack.printStack();
    cout << "\nTHE TOP ELEMENT IS: \n"; 
    cout << VStack.top() << endl;
    cout << "\nTHE THE AVERAGE OF ALL THE VALUES OF THE STACK\n";
    cout << VStack.average();
    
    

}
