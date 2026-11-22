// 876. Middle of the Linked List

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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < count / 2; i++) {
            temp = temp->next;
        }
        return temp;
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

void print(ListNode* h) {
    cout << "[";
    while (h) { cout << h->val << (h->next ? "," : ""); h = h->next; }
    cout << "]";
}

int main() {
    Solution s;
    print(s.middleNode(build({1, 2, 3, 4, 5})));    cout << " (expected [3,4,5])\n";
    print(s.middleNode(build({1, 2, 3, 4, 5, 6}))); cout << " (expected [4,5,6])\n";
    print(s.middleNode(build({1})));                cout << " (expected [1])\n";
    print(s.middleNode(build({1, 2})));             cout << " (expected [2])\n";
    return 0;
}
