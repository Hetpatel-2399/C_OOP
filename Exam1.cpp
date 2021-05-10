/********************************************
Author: HET PATEL
Email:		hpatel9766@conestogac.on.ca
SN:		8319766
*********************************************/
#include <iostream>
#include <ctime>
#include "Node.h"
#include "Containers.h"

int main() 
{
	srand((unsigned int)time(0));
	Container1 myCont1;
	Container2 myCont2;

	for (int x = 1; x < 10; x++)
		myCont1.Push(new Node((rand() % 10)+1));

	myCont1.Display();
	Node* pResult = myCont1.Pop();
	std::cout << pResult->getData() << std::endl;
	pResult->setPtr1(NULL); 
	pResult->setPtr2(NULL);
	delete pResult;// the bug is here, where the de - Allocated the memory using delete.

	pResult = myCont1.Pop();
	myCont1.Display();
	while (pResult)
	{
		myCont2.Push(pResult);
		pResult = myCont1.Pop();
	}

	myCont2.Display();
	return 1;
}



//Comment section of explanation 


//Step 1
//After doing a code walk through, we can understand that data structures are implemented using pointers.There are three filesand they are Node.h, Containers.h, Exam1.cpp.The Exam1.cpp has the main function that drives the program, Containers.h has the implementation of the data structures as there are two container classesand they are Container1and Container2.Both the container classes use objects of the Node class in Node.h file.A node object has data, ptr1and ptr2.In the Exam1.cpp file numbers are generated using the rand functionand firstly pushed in the Container1 object.Then the numbers are popped from container1and pushed to container2 object.
//Container1 class is implementing the concept of Queue.From the code it is observed that a number is pushed at the end of the list.Also in the pop function the first element is popped and returned.Container2 class on the other hand uses both the ptr1 and ptr2 pointers of Node object unlike Container1 that uses only ptr2.The pointers ptr1 and ptr2 act as the left and right of a tree data structure.Also in the push method, number comparisons are doneand accordingly the numbers are placed in the structureand therefore Cotainer2 implements the Binary Search Tree data structure.

//Step 2
//a. Although the program crashes in the display function of the myCont1 object, the bug is actually in Exam1.cpp file on line number 18 where the pResult is de allocated the memory using delete. 
//b. On closely monitoring the address of the pointes in the main function using breakpoints, it was observed that after executing line number 18 and de allocating the memory of the popped element from myCont1 object was causing de allocation of all the other pointers. A possible reason could be that the information is saved in pResult->ptr2 and de allocating the memory for pResult pointer does it for all the sub pointers. 
//c. Possible solution could be pointing both the ptr1and ptr2 of pResult pointer to NULL.This way all the referencing to other elements of the queue is removedand the program does

//step 3
//a. The program goes in a limbo state and nothing happens when the elements are pushed to myCont2 object. This is within the loop from line number 24 to 28.
//b. The reason for the bug is the same that is explained above. The Node object that is popped from myCont1 object i.e. the queue has the information of the pointers of the other elements of the queue and when inserted in the binary search tree the pointers of the node have the same information.
//c. In the Pop function of myCont1 object, the ptr1and ptr2 of the pTemp node is set to NULL before returning.On doing this every time the node is returned from the function the ptr1and ptr2 is set to NULLand the program does not break.

//step 4
//a. The binary tree is traversed using Inorder Depth first traversal. It uses a stack and a temp Node object. Firstly the left or the ptr2 is traversed first and then the right or ptr2 is traversed. The stack keeps the list of nodes traversed.
//b. A stack is used as a data structure in this case to keep the state of the nodes traversed.The other way to traverse the tree is using recursion.Since the function does not take any argument recursion cannot be doneand therefore a stackand a temporary pointer are used to simulate the same.Also inorder depth first traversal prints the data in non - descending order.
// The time complexity of the display function is O(n) i.e.linear time complexity.It is because all the nodes in the binary search tree are traversed.Therefore if there are n nodes in the tree it will take linear time to execute the display function.

