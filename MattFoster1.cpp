#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void printMatrix(int**, int);
void calcPaths(int**, int);
int min(int, int);

int main(int argc, char *argv[]){
	int matrixSize;
	int **adMatrix;
	int inputNum;
	ifstream fileIn;

	fileIn.open(argv[1]);
	fileIn >> matrixSize;

	adMatrix = new int* [matrixSize];

	for(int i = 0; i < matrixSize; i++){
		adMatrix[i] = new int[matrixSize];
	}

	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < matrixSize; j++){
			fileIn >> inputNum;
			adMatrix[i][j] = inputNum;
		}
	}
	cout << "\nOriginal matrix\n";
	printMatrix(adMatrix,matrixSize);
	cout << "\n";
	cout << "\nShortest paths\n";
	calcPaths(adMatrix, matrixSize);
	printMatrix(adMatrix, matrixSize);
	cout << "\n";
	fileIn.close();
	return 0;
}

void printMatrix(int **table, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(table[i][j] == 10000){
				cout << right << setw(5) << "inf";
			}
			else
				cout << right << setw(5) << table[i][j];
		}
		cout << endl;
	}
}

void calcPaths(int **table, int size){
	for(int k = 0; k < size; k++){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				table[i][j] = min(table[i][k] + table[k][j], table[i][j]);
			}
		}
	}
}

int min(int a, int b){
	if(a < b)
		return a;
	else
		return b;
}
