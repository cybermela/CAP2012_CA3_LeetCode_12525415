// 19. Remove Nth Node From End of List

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; i++)
            fast = fast->next;

        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        return dummy.next;
    }
};

ListNode* build(const vector<int>& vals) {
    ListNode dummy;
    ListNode* t = &dummy;
    for (int v : vals) { t->next = new ListNode(v); t = t->next; }
    return dummy.next;
}

void print(ListNode* h) {
    cout << "[";
    while (h) { cout << h->val << (h->next ? "," : ""); h = h->next; }
    cout << "]";
}

int main() {
    Solution s;
    print(s.removeNthFromEnd(build({1, 2, 3, 4, 5}), 2)); cout << " (expected [1,2,3,5])\n";
    print(s.removeNthFromEnd(build({1}), 1));             cout << " (expected [])\n";
    print(s.removeNthFromEnd(build({1, 2}), 1));          cout << " (expected [1])\n";
    print(s.removeNthFromEnd(build({1, 2}), 2));          cout << " (expected [2], remove head)\n";
    print(s.removeNthFromEnd(build({1, 2, 3, 4, 5}), 5)); cout << " (expected [2,3,4,5])\n";
    return 0;
}
