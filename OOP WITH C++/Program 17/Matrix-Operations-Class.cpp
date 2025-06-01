#include <iostream>
using namespace std;

class Matrix
{
private:
    int mat[10][10];
    int rows, cols;

public:
    // Function to input matrix
    void input()
    {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;

        cout << "Enter elements:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display matrix
    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Addition
    void add(Matrix m)
    {
        if (rows != m.rows || cols != m.cols)
        {
            cout << "Addition not possible (dimension mismatch).\n";
            return;
        }

        cout << "Result of Addition:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] + m.mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Subtraction
    void subtract(Matrix m)
    {
        if (rows != m.rows || cols != m.cols)
        {
            cout << "Subtraction not possible (dimension mismatch).\n";
            return;
        }

        cout << "Result of Subtraction:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] - m.mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Multiplication
    void multiply(Matrix m)
    {
        if (cols != m.rows)
        {
            cout << "Multiplication not possible (dimension mismatch).\n";
            return;
        }

        int result[10][10] = {0};

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    result[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }

        cout << "Result of Multiplication:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix A, B;

    cout << "Enter first matrix:\n";
    A.input();

    cout << "Enter second matrix:\n";
    B.input();

    cout << "\nMatrix A:\n";
    A.display();

    cout << "\nMatrix B:\n";
    B.display();

    cout << "\n";
    A.add(B);
    cout << "\n";
    A.subtract(B);
    cout << "\n";
    A.multiply(B);

    return 0;
}
