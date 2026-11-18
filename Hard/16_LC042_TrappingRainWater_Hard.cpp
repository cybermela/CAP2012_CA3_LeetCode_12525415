// 42. Trapping Rain Water

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }
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
