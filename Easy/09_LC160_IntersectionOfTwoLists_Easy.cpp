// 160. Intersection of Two Linked Lists

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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }
        return a;
    }
};

ListNode* build(const vector<int>& vals) {
    ListNode* head = NULL;
    for (int i = (int)vals.size() - 1; i >= 0; i--) {
        ListNode* n = new ListNode(vals[i]);
        n->next = head;
        head = n;
    }
    return head;
}

ListNode* join(ListNode* head, ListNode* tail) {
    if (!head) return tail;
    ListNode* t = head;
    while (t->next) t = t->next;
    t->next = tail;
    return head;
}

void report(ListNode* n) {
    if (n) cout << "Intersected at '" << n->val << "'";
    else   cout << "No intersection";
}

int main() {
    Solution s;
    ListNode* common1 = build({8, 4, 5});
    report(s.getIntersectionNode(join(build({4, 1}), common1), join(build({5, 6, 1}), common1)));
    cout << " (expected 8)\n";

    ListNode* common2 = build({2, 4});
    report(s.getIntersectionNode(join(build({1, 9, 1}), common2), join(build({3}), common2)));
    cout << " (expected 2)\n";

    report(s.getIntersectionNode(build({2, 6, 4}), build({1, 5})));
    cout << " (expected none)\n";

    report(s.getIntersectionNode(NULL, build({1})));
    cout << " (expected none)\n";

    ListNode* same = build({7, 8});
    report(s.getIntersectionNode(same, same));
    cout << " (expected 7)\n";
    return 0;
}
