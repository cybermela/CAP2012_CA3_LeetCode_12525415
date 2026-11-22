// 42. Trapping Rain Water

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int* leftMax = new int[n];
        int* rightMax = new int[n];

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        delete[] leftMax;
        delete[] rightMax;
        return water;
    }
};

int main() {
    Solution s;
    vector<int> h1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(h1) << " (expected 6)\n";
    vector<int> h2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(h2) << " (expected 9)\n";
    vector<int> h3 = {1};
    cout << s.trap(h3) << " (expected 0, single bar)\n";
    vector<int> h4 = {1, 2, 3, 4};
    cout << s.trap(h4) << " (expected 0, increasing)\n";
    vector<int> h5 = {3, 0, 3};
    cout << s.trap(h5) << " (expected 3)\n";
    vector<int> h6 = {0, 0, 0};
    cout << s.trap(h6) << " (expected 0, flat)\n";
    return 0;
}
