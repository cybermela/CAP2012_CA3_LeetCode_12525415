// 4. Median of Two Sorted Arrays

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;
        int low = 0, high = m;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = half - i;

            int maxLeft1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            int maxLeft2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 1)
                    return max(maxLeft1, maxLeft2);
                return (max(maxLeft1, maxLeft2) + (double)min(minRight1, minRight2)) / 2.0;
            } else if (maxLeft1 > minRight2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution s;
    vector<int> a1 = {1, 3}, b1 = {2};
    cout << s.findMedianSortedArrays(a1, b1) << " (expected 2)\n";
    vector<int> a2 = {1, 2}, b2 = {3, 4};
    cout << s.findMedianSortedArrays(a2, b2) << " (expected 2.5)\n";
    vector<int> a3 = {}, b3 = {1};
    cout << s.findMedianSortedArrays(a3, b3) << " (expected 1, one array empty)\n";
    vector<int> a4 = {2}, b4 = {};
    cout << s.findMedianSortedArrays(a4, b4) << " (expected 2)\n";
    vector<int> a5 = {1, 2, 3}, b5 = {4, 5, 6, 7, 8};
    cout << s.findMedianSortedArrays(a5, b5) << " (expected 4.5, no overlap)\n";
    vector<int> a6 = {-5, 3, 6, 12, 15}, b6 = {-12, -10, -6, -3, 4, 10};
    cout << s.findMedianSortedArrays(a6, b6) << " (expected 3)\n";
    return 0;
}
