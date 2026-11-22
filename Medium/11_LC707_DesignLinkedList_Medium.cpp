// 707. Design Linked List

#include <iostream>
using namespace std;

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int v) {
            val = v;
            next = NULL;
        }
    };
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);
        if (head == NULL) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* node = new Node(val);
        node->next = temp->next;
        temp->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            size--;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = del->next;
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
