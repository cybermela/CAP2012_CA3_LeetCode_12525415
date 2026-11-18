// 1342. Number of Steps to Reduce a Number to Zero

#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (num > 0) {
            if (num % 2 == 0)
                num /= 2;
            else
                num -= 1;
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution s;
    cout << s.numberOfSteps(14) << " (expected 6)\n";
    cout << s.numberOfSteps(8) << " (expected 4)\n";
    cout << s.numberOfSteps(123) << " (expected 12)\n";
    cout << s.numberOfSteps(0) << " (expected 0)\n";
    cout << s.numberOfSteps(1) << " (expected 1)\n";
    cout << s.numberOfSteps(1000000) << " (expected 26)\n";
    return 0;
}
