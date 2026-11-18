// 35. Search Insert Position

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return low;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 3, 5, 6};
    cout << s.searchInsert(a, 5) << " (expected 2)\n";
    cout << s.searchInsert(a, 2) << " (expected 1)\n";
    cout << s.searchInsert(a, 7) << " (expected 4)\n";
    cout << s.searchInsert(a, 0) << " (expected 0, before first)\n";
    vector<int> one = {1};
    cout << s.searchInsert(one, 1) << " (expected 0)\n";
    cout << s.searchInsert(one, 2) << " (expected 1)\n";
    return 0;
}
