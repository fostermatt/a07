#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void printMatrix(int**, int, string);
void calcPaths(int**, int);
int min(int,int);

int main(int argc, char *argv[]){
	int **adMatrix, matrixSize;
	ifstream fileIn;
	fileIn.open(argv[1]);
	fileIn >> matrixSize;
	adMatrix = new int* [matrixSize];
	for(int i = 0; i < matrixSize; i++){ // create and populate adjacency matrix
		adMatrix[i] = new int[matrixSize];
		for(int j = 0; j < matrixSize; j++)
			fileIn >> adMatrix[i][j];
	}
	printMatrix(adMatrix,matrixSize,"\nOriginal matrix:\n");
	calcPaths(adMatrix, matrixSize);
	printMatrix(adMatrix, matrixSize,"\nShortest paths:\n");
	fileIn.close();
	return 0;
}
// print formatted adjacency matrix with title
void printMatrix(int **table, int size, string title){
	cout << title;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(table[i][j] == 10000)
				cout << left << setw(6) << "inf";
			else
				cout << left << setw(6) << table[i][j];
		}
		cout << endl;
	}
}
// Floyd-Warshall shortest path algorithm
void calcPaths(int **table, int size){
	for(int k = 0; k < size; k++){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++)
				table[i][j] = min(table[i][k] + table[k][j], table[i][j]);
		}
	}
}
// return minimum input value
int min(int a, int b){
	if(a < b)
		return a;
	return b;
}
