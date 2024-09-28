#include <iostream>
using namespace std;

#define MAX 10

void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(int rows, int cols, int matrix1[MAX][MAX], int matrix2[MAX][MAX]) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout << "Result of Addition:\n";
    printMatrix(rows, cols, result);
}

void subtractMatrices(int rows, int cols, int matrix1[MAX][MAX], int matrix2[MAX][MAX]) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    cout << "Result of Subtraction:\n";
    printMatrix(rows, cols, result);
}

void multiplyMatrices(int rows1, int cols1, int matrix1[MAX][MAX], int rows2, int cols2, int matrix2[MAX][MAX]) {
    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Column count of first matrix must be equal to row count of second matrix.\n";
        return;
    }
    int result[MAX][MAX] = {0};
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    cout << "Result of Multiplication:\n";
    printMatrix(rows1, cols2, result);
}

void transposeMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    cout << "Transpose of the Matrix:\n";
    printMatrix(cols, rows, result);
}

void inputMatrix(int rows, int cols, int matrix[MAX][MAX], char matrixName) {
    cout << "Enter elements of matrix " << matrixName << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrixName << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int main() {
    int choice;
    int rows1, cols1, rows2, cols2;
    int matrix1[MAX][MAX], matrix2[MAX][MAX];

    do {
        cout << "\nMatrix Calculator:\n";
        cout << "1. Add Matrices\n";
        cout << "2. Subtract Matrices\n";
        cout << "3. Multiply Matrices\n";
        cout << "4. Transpose a Matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Addition
                cout << "Enter the number of rows and columns for both matrices: ";
                cin >> rows1 >> cols1;
                inputMatrix(rows1, cols1, matrix1, 'A');
                inputMatrix(rows1, cols1, matrix2, 'B');
                addMatrices(rows1, cols1, matrix1, matrix2);
                break;
            case 2:
                // Subtraction
                cout << "Enter the number of rows and columns for both matrices: ";
                cin >> rows1 >> cols1;
                inputMatrix(rows1, cols1, matrix1, 'A');
                inputMatrix(rows1, cols1, matrix2, 'B');
                subtractMatrices(rows1, cols1, matrix1, matrix2);
                break;
            case 3:
                // Multiplication
                cout << "Enter rows and columns for Matrix A: ";
                cin >> rows1 >> cols1;
                cout << "Enter rows and columns for Matrix B: ";
                cin >> rows2 >> cols2;
                inputMatrix(rows1, cols1, matrix1, 'A');
                inputMatrix(rows2, cols2, matrix2, 'B');
                multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2);
                break;
            case 4:
                // Transpose
                cout << "Enter the number of rows and columns for the matrix: ";
                cin >> rows1 >> cols1;
                inputMatrix(rows1, cols1, matrix1, 'A');
                transposeMatrix(rows1, cols1, matrix1);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
