// 54. Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0, bottom = (int)matrix.size() - 1;
        int left = 0, right = (int)matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;

            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
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
