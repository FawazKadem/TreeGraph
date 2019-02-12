
// tree.c contains functions to print the parent, left child, or right child of a node within a binary tree represented with an array. Also contains function to find the closest common ancestor of two nodes
// Contains helper function getIndex to find the index of a node with a given value
// Author: Fawaz M. Mohammad, under supervision of Ali Hamou
#include <stdio.h>

// INPUT: 'bt', a binary tree.
//	'node', a node in the tree.
// OUTPUT: the index of given value in the tree.

int getIndex(int *bt, int node){



	
// for loop iterates through array until the value of the node is found and then returns the index where the value is located
	for (int i = 1; i <= (bt[0]); i++)
	{
		if ((bt[i]) == node){
			
			return i; //returns index of node with given value

		}
	}

	return -1; //if not found, the method returns -1 signaling that the value is not within the given tree. Will also always return -1 if tree is empty

}

// INPUT: 'bt', a binary tree.
//	'node ', a node in the tree.
// OUPUT: print the parent node of 'node'. 
void printParentNode (int *bt, int node){
//...

	int nodeIndex = getIndex(bt, node); //using helper method getIndex to determine index of given node



	if (nodeIndex == 1)
	{
		printf("Error: Root node has no parent\n"); //if nodeIndex is 1, the node is the root and has no parent. Therefore, error.
	} else if (nodeIndex == -1){
		printf("Invalid input. Nodes do not exist in tree. Ensure that the tree is both not empty and that the given nodes are contained within it.\n"); // if getIndex returns -1, the node is not within the tree. Therefore, error
	} else{

		int parentNodeIndex = (nodeIndex)/2; //since a parents index is the index of its child divided by 2. (since it is an int value, it will remove the .5 if using a right child)

		printf("Parent of node %d is %d\n", node, bt[parentNodeIndex]); //prints parent node 
	}

}


// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the left child of 'node'. 
void printLeftChildNode (int *bt, int node){


	int nodeIndex = getIndex(bt, node); //finds index of node


	int LeftChildNode = nodeIndex*2; //find index value of left child

	if (nodeIndex == -1){

		printf("Invalid input. Nodes do not exist in tree. Ensure that the tree is both not empty and that the given nodes are contained within it.\n"); // if getIndex returns -1, the node is not within the tree. Therefore, error

	} else{


		if (LeftChildNode > (bt[0])){
			printf("Error: Node does not have a Left Child\n"); //if node*2 is greater than size of tree, then the node doesn't have a left child

		} else{

			printf("Left child of node %d is %d\n",node, bt[LeftChildNode]);


	}

}
}

// INPUT: 'bt', a binary tree
//	'node', a node in the tree.
// OUPUT: print the right child of 'node' 
void printRightChildNode (int *bt, int node){


		

	int nodeIndex = getIndex(bt, node); //finds index of node

	int RightChildNode = (nodeIndex*2) + 1; //find index value of right child

	if (nodeIndex == -1){

		printf("Invalid input. Nodes do not exist in tree. Ensure that the tree is both not empty and that the given nodes are contained within it.\n");

	} else{


		if (RightChildNode >= bt[0]){
			printf("Error: Node does not have a Right Child\n"); //if node*2+1 is greater than the size of the tree, then node has no right child

		} else{

			printf("Right Child of node %d is %d\n", node, bt[RightChildNode]);


	}

}



}

// INPUT: 'bt', a binary tree
//	'node1', a node in the tree.
//	'node2', a node in the tree.
// OUPUT: print the nearest ancestor of 'node1' and 'node2'. 
void printNearestCommonAncestor(int *bt, int node1, int node2){
//assumes a node is a common ancestor of itself. 

	int node1Index = getIndex(bt,node1), node2Index = getIndex(bt,node2); //gets index of both nodes

	int node1Path[node1Index], node2Path[node2Index]; //path variables to record all ancestors of each

	node1Path[0] = node1Index; //adds node1 to its own path
	node2Path[0] = node2Index; //addds node2 to its own path

	
	int sizeNode1Path = 1, sizeNode2Path = 1; //variable to keep track of size of path

	int parent1Index = node1Index, parent2Index = node2Index;

	if (node1Index == -1 || node2Index == -1){
		printf("Invalid input. Nodes do not exist in tree. Ensure that the tree is both not empty and that the given nodes are contained within it.\n");


	} else{

		// adds all ancestors to path
		while (parent1Index > 1){
			parent1Index = parent1Index/2;
			node1Path[sizeNode1Path] = parent1Index;
			sizeNode1Path++; 
		
	}
		//adds all ancestors to path
		while (parent2Index > 1){
			parent2Index = parent2Index/2;
			node2Path[sizeNode2Path] = parent2Index;
			sizeNode2Path++; 
	}
		


	int found = 0; //boolean to determine if an ancestor has been found
	for (int i=0; i <= sizeNode1Path; i++){ //for loop iterates over both nodes' path and finds the nearest common ancestor. This works since the paths are sorted from closest to furthers ancetors
		
		for (int j=0; j <= sizeNode2Path; j++){
			
			if (node1Path[i] == node2Path[j]){

				found = 1;
				printf("Nearest Common Ancestor of %d and %d is %d\n", node1, node2, bt[node1Path[i]] );
				break;
			}
			

		}

		if (found == 1) break; //breaks loop if found 


	}
	
	}

}


/* binaryTree is an array to encode a binary tree.
The first element of this array is used to encode the number of nodes. */

// main function to test other functions

int main() {

	int binaryTree[11] = {10, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

	printParentNode(binaryTree, 16);
	printParentNode(binaryTree, 3);

	printLeftChildNode(binaryTree, 7);
	printLeftChildNode(binaryTree, 9);

	printRightChildNode(binaryTree, 7);
	printRightChildNode(binaryTree, 10);

	printNearestCommonAncestor(binaryTree, 8, 1);
	printNearestCommonAncestor(binaryTree, 8, 9);

	return 0;
}

