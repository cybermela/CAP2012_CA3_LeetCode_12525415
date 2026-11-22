// 4. Median of Two Sorted Arrays

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int i = 0, j = 0;
        int prev = 0, curr = 0;
        for (int count = 0; count <= total / 2; count++) {
            prev = curr;
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
        }
        if (total % 2 == 1) return curr;
        return (prev + curr) / 2.0;
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
