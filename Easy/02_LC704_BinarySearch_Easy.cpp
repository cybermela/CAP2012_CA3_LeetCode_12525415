// 704. Binary Search

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    cout << s.search(a, 9) << " (expected 4)\n";
    cout << s.search(a, 2) << " (expected -1)\n";
    vector<int> one = {5};
    cout << s.search(one, 5) << " (expected 0)\n";
    cout << s.search(one, -5) << " (expected -1)\n";
    cout << s.search(a, -1) << " (expected 0, first element)\n";
    cout << s.search(a, 12) << " (expected 5, last element)\n";
    return 0;
}
