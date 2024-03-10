
/*
Q1. Write a Matrix class. Allocate memory dynamically in parameterized constructor. Also write
parameter-less constructor. Write accept() and print() functions.
Also provide add(), subtract(), multiply() and transpose() function.
*/
#include <iostream>

using namespace std;

class Matrix
{
    int row, col;

public:
    int **arr;
    Matrix()
    {
        row = 0;
        col = 0;
    }

    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
    }

    void accept(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    void displayMatrix()
    {
        cout<<"\n";
        for (int r = 0; r < this->row; r++)
        {
            for (int c = 0; c < this->col; c++)
            {
                cout << arr[r][c] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix()
    {
        for(int i=0; i<row; i++)
        {
            delete[] arr[i];
            arr[i] = NULL;
        }
        delete[] arr;
        arr = NULL;
    }
};

void addMatrix(Matrix &m1, Matrix &m2, int arow, int acol)
{
    cout << "Addition of array is : ";
    Matrix result(arow, acol);
    for (int row = 0; row < arow; row++)
    {
        for (int col = 0; col < acol; col++)
        {
            result.arr[row][col] = m1.arr[row][col] + m2.arr[row][col];
        }
    }
    result.displayMatrix();
}

void subMatrix(Matrix &m1, Matrix &m2, int arow, int acol)
{
    cout << "Substraction of array is : ";
    Matrix result(arow, acol);
    for (int row = 0; row < arow; row++)
    {
        for (int col = 0; col < acol; col++)
        {
            result.arr[row][col] = m1.arr[row][col] - m2.arr[row][col];
        }
    }
    result.displayMatrix();
}

void mulMatrix(Matrix &m1, Matrix &m2, int arow, int acol)
{
    cout << "Multiplication of array is : ";
    Matrix result(arow, acol);
    for (int row = 0; row < arow; row++)
    {
        for (int col = 0; col < acol; col++)
        {
            for(int k=0; k<col;k++)
            {
                result.arr[row][col] = m1.arr[row][k] - m2.arr[k][col];
            }
        }
    }
    result.displayMatrix();
}

void transposeMatrix(Matrix &m, int arow, int acol)
{
    cout << "Transpose of array is : ";
    Matrix result(arow, acol);
    for (int row = 0; row < acol; row++)
    {
        for (int col = 0; col < arow; col++)
        {
                result.arr[row][col] = m.arr[col][row];
            
        }
    }
    result.displayMatrix();
}

enum EMatrix
{
    EXIT,
    ACCEPT,
    ADD,
    SUB,
    MUL,
    TRANSPOSE
};

int main()
{
    int row, col, choice,t;
    cout << "Enter rows for Matrix : ";
    cin >> row;
    cout << "Enter columns for Matrix : ";
    cin >> col;
    Matrix s1(row, col);
    Matrix s2(row, col);

    do
    {
        cout << "\n0.Exit.";
        cout << "\n1.Accept Matrix.";
        cout << "\n2.Additon of matrix.";
        cout << "\n3.Substraction of matrix.";
        cout << "\n3.Multiplication of matrix."; 
        cout << "\n3.Transpose of matrix.";
        cout << "\nEnter choice : ";
        cin >> choice;

        switch (EMatrix(choice))
        {
        case ACCEPT:
            cout << "\nEnter values for Matrix one : ";
            s1.accept(row, col);
            s1.displayMatrix();
            cout << "\nEnter values for Matrix two : ";
            s2.accept(row, col);
            s2.displayMatrix();
            break;
        case ADD:
            addMatrix(s1, s2, row, col);
            break;

        case SUB:
            subMatrix(s1,s2,row,col);
            break;
        case MUL:
            mulMatrix(s1,s2,row,col);
            break;
        case TRANSPOSE:
            cout<<"\nDo you want transpose matrix[1] or matrix[2] : ";
            cin>>t;
            if(t==1)
            {
                transposeMatrix(s1,row,col);
            }
            else{
                transposeMatrix(s2,row,col);
            }
            break;
        }

    } while (choice != 0);

    return 0;
}