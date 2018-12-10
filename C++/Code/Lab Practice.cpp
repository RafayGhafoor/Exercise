#include <iostream>

using namespace std;

// Question No. 1
void initMatrix(int **matrix, int rows, int columns) {
  // Initialize the given matrix entries to 0
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[rows];
    
    for (int j = 0; j < columns; j++)
      matrix[i][j] = 0;
  }
}

// Question No. 2
void printMatrix(int **matrix, int rows, int columns) {
  // Print the elements of the matrix
  for (int i = 0; i < rows; i++) {
    
    for (int j = 0; j < columns; j++)
      cout << matrix[i][j] << " ";
    
    cout << endl;
  }
}

int main() {

  int row, column;
  cout << "Enter Number of Rows: ";
  cin >> row;
  cout << "Enter Number of Columns: ";
  cin >> column;
  
  int **matrixA = new int *[row];
  
  initMatrix(matrixA, row, column);
  printMatrix(matrixA, row, column);
}
