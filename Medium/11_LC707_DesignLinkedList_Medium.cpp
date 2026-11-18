// 707. Design Linked List

#include <iostream>
using namespace std;

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(NULL) {}
    };
    Node* dummy;
    int size;

public:
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    ~MyLinkedList() {
        Node* curr = dummy;
        while (curr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = dummy->next;
        for (int i = 0; i < index; i++) curr = curr->next;
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node* prev = dummy;
        for (int i = 0; i < index; i++) prev = prev->next;
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* prev = dummy;
        for (int i = 0; i < index; i++) prev = prev->next;
        Node* del = prev->next;
        prev->next = del->next;
        delete del;
        size--;
    }
};

int main() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);
    cout << list.get(1) << " (expected 2)\n";
    list.deleteAtIndex(1);
    cout << list.get(1) << " (expected 3)\n";

    cout << list.get(5) << " (expected -1, out of range)\n";
    list.addAtIndex(5, 10);
    cout << list.get(2) << " (expected -1)\n";
    list.addAtIndex(2, 4);
    cout << list.get(2) << " (expected 4)\n";
    list.deleteAtIndex(0);
    cout << list.get(0) << " (expected 3)\n";
    list.deleteAtIndex(7);
    cout << list.get(1) << " (expected 4)\n";
    return 0;
}
