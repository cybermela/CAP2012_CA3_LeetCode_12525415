// 225. Implement Stack using Queues

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int rotations = (int)q.size() - 1;
        while (rotations-- > 0) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topVal = q.front();
        q.pop();
        return topVal;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    cout << boolalpha;
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.top() << " (expected 2)\n";
    cout << st.pop() << " (expected 2)\n";
    cout << st.empty() << " (expected false)\n";

    MyStack s2;
    for (int i = 1; i <= 5; i++) s2.push(i);
    cout << "pop order: ";
    while (!s2.empty()) cout << s2.pop() << " ";
    cout << "(expected 5 4 3 2 1)\n";
    cout << s2.empty() << " (expected true)\n";
    return 0;
}
