// 203. Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode* curr = &dummy;
        while (curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode* del = curr->next;
                curr->next = del->next;
                delete del;
            } else {
                curr = curr->next;
            }
        }
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
    print(s.removeElements(build({1, 2, 6, 3, 4, 5, 6}), 6)); cout << " (expected [1,2,3,4,5])\n";
    print(s.removeElements(build({}), 1));                    cout << " (expected [])\n";
    print(s.removeElements(build({7, 7, 7, 7}), 7));          cout << " (expected [])\n";
    print(s.removeElements(build({1, 2, 3}), 1));             cout << " (expected [2,3], remove head)\n";
    print(s.removeElements(build({1, 2, 3}), 4));             cout << " (expected [1,2,3], not found)\n";
    return 0;
}
