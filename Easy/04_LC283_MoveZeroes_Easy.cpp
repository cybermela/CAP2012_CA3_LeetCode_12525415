// 283. Move Zeroes

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[k] = nums[i];
                k++;
            }
        }
        while (k < n) {
            nums[k] = 0;
            k++;
        }
    }
};

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << v[i] << (i + 1 < v.size() ? "," : "");
    cout << "]";
}

int main() {
    Solution s;
    vector<vector<int>> tests = {
        {0, 1, 0, 3, 12},
        {0},
        {1, 2, 3},
        {0, 0, 0},
        {4, 0, 5, 0, 0, 6}
    };
    for (auto& t : tests) {
        s.moveZeroes(t);
        print(t);
        cout << "\n";
    }
    return 0;
}
