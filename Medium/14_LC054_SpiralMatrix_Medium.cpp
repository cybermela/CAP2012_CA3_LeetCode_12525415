// 54. Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while ((int)result.size() < total) {
            for (int j = left; j <= right && (int)result.size() < total; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            for (int i = top; i <= bottom && (int)result.size() < total; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            for (int j = right; j >= left && (int)result.size() < total; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
            for (int i = bottom; i >= top && (int)result.size() < total; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << v[i] << (i + 1 < v.size() ? "," : "");
    cout << "]";
}

int main() {
    Solution s;
    vector<vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(s.spiralOrder(m1)); cout << " (expected [1,2,3,6,9,8,7,4,5])\n";

    vector<vector<int>> m2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    print(s.spiralOrder(m2)); cout << " (expected [1,2,3,4,8,12,11,10,9,5,6,7])\n";

    vector<vector<int>> m3 = {{7}};
    print(s.spiralOrder(m3)); cout << " (expected [7])\n";
    vector<vector<int>> m4 = {{1, 2, 3}};
    print(s.spiralOrder(m4)); cout << " (expected [1,2,3], single row)\n";
    vector<vector<int>> m5 = {{1}, {2}, {3}};
    print(s.spiralOrder(m5)); cout << " (expected [1,2,3], single column)\n";
    return 0;
}
