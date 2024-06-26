#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        // Check if the first row has any zeros
        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        // Check if the first column has any zeros
        for (int i = 0; i < n; ++i) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        // Use the first row and column as markers
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes based on the markers in the first row and column
        for (int i = 1; i < n; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < m; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row separately if it had any zeros
        if (firstRowHasZero) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Handle the first column separately if it had any zeros
        if (firstColHasZero) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
