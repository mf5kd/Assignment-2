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
    // Read data from file into the array
    while (fin.good()) {
        fileData.resize(c + 1);
        fin >> fileData[c];
        c++;
    }
    fin.close();

    SingleLinkList SList(fileData);
    VectorStack VStack;

    cout << "Single Link List\n";
    cout << SList.front()->data << endl;
    cout << SList.back()->data << endl;
    cout << SList.size() << endl;
    SList.printList();
    
    cout << "Vector Stack\n";


    
    for (int x = 0; x < 10; x++) {
        VStack.push(x);
    }

    VStack.printStack();
    
    

}
