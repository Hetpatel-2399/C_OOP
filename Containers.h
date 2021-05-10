/********************************************
Author: HET PATEL
Email:		hpatel9766@conestogac.on.ca
SN:		8319766
*********************************************/
#pragma once
#include "Node.h"
#include<stack>

using namespace std;

class Container1
{
	Node* pHead;

public:
	Container1() : pHead(new Node) {};
	~Container1() { delete pHead; };

	void Push(Node* pNewNode)
	{
		Node* pTmp = pHead;
		while (pTmp->getPtr2())
			pTmp = pTmp->getPtr2();

		pTmp->setPtr2(pNewNode);
	};

	Node* Pop()
	{
		if (pHead)
		{
			Node* pTmp = pHead;
			pHead = pTmp->getPtr2();
			pTmp->setPtr1(NULL);
			pTmp->setPtr2(NULL);
			return pTmp;
		}
		else
			return pHead;
	};

	void Display() // this where the program crashes 
	{
		if (pHead)
		{
			Node* pTmp = pHead;
			while (pTmp->getPtr2())
			{
				std::cout << pTmp->getData() << " ";
				pTmp = pTmp->getPtr2();
			}
			std::cout << pTmp->getData() << std::endl;
		}
	};
};

class Container2
{
	Node* pHead;

public:
	Container2() : pHead(new Node(5)) {};
	~Container2() { delete pHead; };

	void Push(Node* pNewNode)
	{
		Node* pCurrent = pHead;
		Node* pNext = pHead;

		while (pNext)
		{
			pCurrent = pNext;
			if (pNewNode->getData() > pCurrent->getData())
				pNext = pCurrent->getPtr1();
			else if (pNewNode->getData() <= pCurrent->getData())
				pNext = pCurrent->getPtr2();
		}

		if (pNewNode->getData() > pCurrent->getData())
			pCurrent->setPtr1(pNewNode);
		else if (pNewNode->getData() <= pCurrent->getData())
			pCurrent->setPtr2(pNewNode);
	};

	void Display()
	{
		//Inorder depth the first traversal of trees which stores the node traversed
		std::stack<Node*> stackNodes;
		Node* temp = pHead;

		while (temp != NULL || stackNodes.empty())//Loop until all the nodes are not transved
		{
			while (temp != NULL) //left nodes are traversed first
			{
				stackNodes.push(temp);
				temp = temp->getPtr2();
			}
			temp = stackNodes.top();
			std::cout << temp->getData() << " ";
			stackNodes.pop();

			temp = temp->getPtr1(); // after the left right side is traversed

		}

	};
};

