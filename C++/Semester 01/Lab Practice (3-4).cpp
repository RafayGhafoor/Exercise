#include <iostream>

using namespace std;

// Question No. 1
void initMatrix(int **matrix, int rows, int columns)
{
    // Initialize the given matrix entries to 0
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];

        for (int j = 0; j < columns; j++)
            matrix[i][j] = 0;
    }
}

void getInput(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            cout << "Enter Element at Row " << i << " and Column " << j << ": ";
            cin >> matrix[i][j];
        }
}

void addMatrix(int **matrix, int **matrix1, int **result, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << matrix[i][j] + matrix1[i][j] << "    ";
            result[i][j] = matrix[i][j] + matrix1[i][j];
        }
        cout << endl;
    }
}

void TestMatrixAddition()
{
    int row, column;
    cout << "Enter Number of Rows: ";
    cin >> row;
    cout << "Enter Number of Columns: ";
    cin >> column;

    if (row == column)
    {
        int **matrixA = new int *[row];
        int **matrixB = new int *[row];
        int **matrixC = new int *[row];

        initMatrix(matrixA, row, column);
        initMatrix(matrixB, row, column);
        initMatrix(matrixC, row, column);

        // endl and \n are equivalent
        cout << "Enter Elements for Matrix A\n";
        getInput(matrixA, row, column);
        cout << "\nEnter Elements for Matrix B\n";
        getInput(matrixB, row, column);

        addMatrix(matrixA, matrixB, matrixC, row, column);
    }

    else
        cout << "Matrix don't have same order (row != column)\nCannot be Added!";
}
int main() { TestMatrixAddition(); }
