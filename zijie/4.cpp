#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSum = INT_MIN;

    vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0)); // 初始化值是0

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            int currentSum = prefixSum[i][j] - prefixSum[i - k][j] - prefixSum[i][j - k] + prefixSum[i - k][j - k];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int k = 2;
    cout << "Maximum sum of " << k << "x" << k << " submatrix: " << maxSumSubmatrix(matrix, k) << endl;
    return 0;
}
