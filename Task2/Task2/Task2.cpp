#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int countNonZeroColumns(const vector<vector<int>>& matrix) {
    int cols = matrix[0].size();
    int nonZeroColsCount = 0;
    for (int j = 0; j < cols; ++j) {
        bool hasZero = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            nonZeroColsCount++;
        }
    }
    return nonZeroColsCount;
}

int rowCharacteristic(const vector<int>& row) {
    int sum = 0;
    for (int elem : row) {
        if (elem > 0 && elem % 2 == 0) {
            sum += elem;
        }
    }
    return sum;
}

void sortRowsByCharacteristic(vector<vector<int>>& matrix) {
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        return rowCharacteristic(a) < rowCharacteristic(b);
        });
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    srand(static_cast<unsigned int>(time(0)));
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }

    cout << "Generated matrix:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    int nonZeroCols = countNonZeroColumns(matrix);
    cout << "Number of columns without zero elements: " << nonZeroCols << endl;

    sortRowsByCharacteristic(matrix);

    cout << "Matrix after sorting rows by the sum of positive even elements:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
