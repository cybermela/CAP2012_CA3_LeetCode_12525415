// 946. Validate Stack Sequences

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && j < (int)popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    cout << boolalpha;
    vector<int> p1 = {1, 2, 3, 4, 5}, q1 = {4, 5, 3, 2, 1};
    cout << s.validateStackSequences(p1, q1) << " (expected true)\n";
    vector<int> p2 = {1, 2, 3, 4, 5}, q2 = {4, 3, 5, 1, 2};
    cout << s.validateStackSequences(p2, q2) << " (expected false)\n";
    vector<int> p3 = {1}, q3 = {1};
    cout << s.validateStackSequences(p3, q3) << " (expected true, single)\n";
    vector<int> p4 = {1, 2, 3}, q4 = {1, 2, 3};
    cout << s.validateStackSequences(p4, q4) << " (expected true, pop right after push)\n";
    vector<int> p5 = {1, 2, 3}, q5 = {3, 1, 2};
    cout << s.validateStackSequences(p5, q5) << " (expected false)\n";
    return 0;
}
