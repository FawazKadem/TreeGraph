//graph.c has functions for printing the vertices and edges of a given graph as well as a function to determine if there is a direct path between two vertices
//Author: Fawaz M. Mohammad, under supervision of Ali Hamou
#include <stdio.h>

//INPUT: 'N',number of vertices
// 'G[][N]' graph with N vertices
// OUTPUT: Prints each vertex
void printVertices(int N, int G[][N]) {

	printf("This graph has vertices: \n");
	for(int i=0;i<N;i++){ //Iterates once per vertex and prints each vertex.
		printf("Vertex: %d\n",i);


	}

	if (N=0) printf("Graph has no vertices and is empty\n"); //Error message if graph is empty



}


//INPUT: 'N',number of vertices
// 'G[][N]' graph with N vertices
// OUTPUT: Prints each edge
void printEdges(int N, int G[][N]) {

	printf("This graph has edges: \n");
	for(int i=0;i<N;i++){ //iterates over each combination of vertices in the graph and prints where edges exist.
		for (int j=0;j<N;j++){
			if (G[i][j] == 1){

				printf("[%d,%d]\n", i, j);
			}

		}

	}

	if (N=0) printf("Graph has no vertices and is empty. Therefore, it also has no edges\n");

}


//INPUT: 'N',number of vertices
// 'G[][N]' graph with N vertices
// 'v1' a vertex
// 'v2' a vertex
// OUTPUT: Prints whether or not there is a direct path between v1 and v2
void isThereAPath(int N, int G[][N], int v1, int v2) {

		if (v1 >= N  || v2 >= N || N < 1){
			printf("Error: Invalid Vertices/Graph is empty"); //Error message for when given vertices are not contained within the graph. Also addresses if there is an empty graph.
		} else{

			if (G[v1][v2] == 1) { // if the intersection of vertices = 1, then there is a direct path. Otherwise there is not.
			printf("There is a path between %d and %d\n", v1, v2);
			} else printf("There is no path between %d and %d\n", v1, v2);

		}	
}

#define N 5

// main function to test other functions

int main() {

	int Graph[N][N] = { 	
				{0,1,0,0,1},
				{1,0,0,0,1},
				{0,0,0,1,0},
				{0,0,1,0,0},
				{1,1,0,0,0}
			};

	printVertices(N, Graph);
	printEdges(N, Graph);
	isThereAPath(N, Graph, 0, 1);
	isThereAPath(N, Graph, 0, 3);

	return 0;

}

