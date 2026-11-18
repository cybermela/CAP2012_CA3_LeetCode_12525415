// 141. Linked List Cycle

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

ListNode* build(const vector<int>& vals, int pos) {
    if (vals.empty()) return NULL;
    vector<ListNode*> nodes;
    for (int v : vals) nodes.push_back(new ListNode(v));
    for (size_t i = 0; i + 1 < nodes.size(); i++) nodes[i]->next = nodes[i + 1];
    if (pos >= 0) nodes.back()->next = nodes[pos];
    return nodes[0];
}

int main() {
    Solution s;
    cout << boolalpha;
    cout << s.hasCycle(build({3, 2, 0, -4}, 1)) << " (expected true)\n";
    cout << s.hasCycle(build({1, 2}, 0)) << " (expected true)\n";
    cout << s.hasCycle(build({1}, -1)) << " (expected false)\n";
    cout << s.hasCycle(build({}, -1)) << " (expected false, empty list)\n";
    cout << s.hasCycle(build({1}, 0)) << " (expected true, self loop)\n";
    cout << s.hasCycle(build({1, 2, 3, 4, 5}, -1)) << " (expected false)\n";
    return 0;
}
