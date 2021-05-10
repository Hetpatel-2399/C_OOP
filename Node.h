#pragma once
#include <iostream>

/********************************************
Author: HET PATEL
Email:		hpatel9766@conestogac.on.ca
SN:		8319766
*********************************************/
class Node
{
	int data;
	Node* ptr1;
	Node* ptr2;

public:
	Node() : data(0), ptr1(nullptr), ptr2(nullptr) {};					
	Node(int newData) : data(newData), ptr1(nullptr), ptr2(nullptr) {};	

	void setPtr1(Node* ptr) { ptr1 = ptr; };
	Node* getPtr1() { return ptr1; };
	void setPtr2(Node* ptr) { ptr2 = ptr; };
	Node* getPtr2() { return ptr2; };
	int getData() { return data; };
	
	~Node()
	{
		if (ptr1)
			delete ptr1;

		if (ptr2)
			delete ptr2;
	}
};