// 641. Design Circular Deque

#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
    int* arr;
    int front;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) {
        arr = new int[k];
        capacity = k;
        front = 0;
        count = 0;
    }

    ~MyCircularDeque() {
        delete[] arr;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        int rear = (front + count) % capacity;
        arr[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[(front + count - 1) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

int main() {
    cout << boolalpha;
    MyCircularDeque dq(3);
    cout << dq.insertLast(1)  << " (expected true)\n";
    cout << dq.insertLast(2)  << " (expected true)\n";
    cout << dq.insertFront(3) << " (expected true)\n";
    cout << dq.insertFront(4) << " (expected false, full)\n";
    cout << dq.getRear()      << " (expected 2)\n";
    cout << dq.isFull()       << " (expected true)\n";
    cout << dq.deleteLast()   << " (expected true)\n";
    cout << dq.insertFront(4) << " (expected true)\n";
    cout << dq.getFront()     << " (expected 4)\n";

    MyCircularDeque d2(1);
    cout << d2.getFront()     << " (expected -1, empty)\n";
    cout << d2.deleteFront()  << " (expected false, empty)\n";
    cout << d2.insertFront(9) << " (expected true)\n";
    cout << d2.getRear()      << " (expected 9)\n";
    cout << d2.deleteLast()   << " (expected true)\n";
    cout << d2.isEmpty()      << " (expected true)\n";
    return 0;
}
