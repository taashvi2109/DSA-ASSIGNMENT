#include <iostream>
using namespace std;

const int MAXSIZE = 1000;

struct MaxHeap {
    int arr[MAXSIZE];
    int size;
};

void initHeap(MaxHeap &h) {
    h.size = 0;
}

bool isEmpty(MaxHeap &h) {
    return h.size == 0;
}

bool isFull(MaxHeap &h) {
    return h.size == MAXSIZE;
}

void swapInt(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void insertKey(MaxHeap &h, int key) {
    if (isFull(h)) {
        cout << "Overflow\n";
        return;
    }
    int i = h.size;
    h.arr[i] = key;
    h.size++;
    while (i != 0) {
        int p = (i - 1) / 2;
        if (h.arr[p] < h.arr[i]) {
            swapInt(h.arr[p], h.arr[i]);
            i = p;
        } else break;
    }
}

int getMax(MaxHeap &h) {
    if (isEmpty(h)) return -1;
    return h.arr[0];
}

int extractMax(MaxHeap &h) {
    if (isEmpty(h)) {
        cout << "Underflow\n";
        return -1;
    }
    int root = h.arr[0];
    h.arr[0] = h.arr[h.size - 1];
    h.size--;
    int i = 0;
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (l < h.size && h.arr[l] > h.arr[largest]) largest = l;
        if (r < h.size && h.arr[r] > h.arr[largest]) largest = r;
        if (largest != i) {
            swapInt(h.arr[i], h.arr[largest]);
            i = largest;
        } else break;
    }
    return root;
}

void display(MaxHeap &h) {
    if (isEmpty(h)) {
        cout << "Empty\n";
        return;
    }
    for (int i = 0; i < h.size; i++) cout << h.arr[i] << " ";
    cout << "\n";
}

int main() {
    MaxHeap h;
    initHeap(h);
    int choice, val;
    while (true) {
        cout << "\n1.Insert 2.Get Max 3.Extract Max 4.Display 5.Exit\n";
        cin >> choice;
        if (choice == 5) break;
        if (choice == 1) {
            cin >> val;
            insertKey(h, val);
        } else if (choice == 2) {
            int m = getMax(h);
            if (m == -1 && isEmpty(h)) cout << "Empty\n";
            else cout << m << "\n";
        } else if (choice == 3) {
            int m = extractMax(h);
            if (!(m == -1 && isEmpty(h))) cout << m << "\n";
        } else if (choice == 4) {
            display(h);
        }
    }
    return 0;
}
