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
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        if (n == len) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        temp = head;
        for (int i = 1; i < len - n; i++) {
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
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
