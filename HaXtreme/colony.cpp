#include <iostream>
#include <vector>

using namespace std;

// Function to print elements of a matrix in spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    while (!matrix.empty()) {
        // Traverse the first row
        for (int elem : matrix[0]) {
            result.push_back(elem);
        }
        // Remove the first row
        matrix.erase(matrix.begin());

        // Rotate the remaining matrix 90 degrees counterclockwise
        if (!matrix.empty()) {
            vector<vector<int>> newMatrix;
            int n = matrix[0].size();
            for (int i = n - 1; i >= 0; i--) {
                vector<int> newRow;
                for (int j = 0; j < matrix.size(); j++) {
                    newRow.push_back(matrix[j][i]);
                }
                newMatrix.push_back(newRow);
            }
            matrix = newMatrix;
        }
    }
    return result;
}

int main() {
    int matrix_size;
    cin >> matrix_size;
    vector<vector<int>> matrix(matrix_size, vector<int>(matrix_size));

    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> output = spiralOrder(matrix);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ' ';
    }

    return 0;
}
