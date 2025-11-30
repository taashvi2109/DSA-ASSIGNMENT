#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void enqueue(int x) {
        if (isFull())
            cout << "Queue Full\n";
        else
            arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty())
            cout << "Queue Empty\n";
        else
            front++;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty())
            cout << "Empty\n";
        else {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int ch, val;

    while (true) {
        cout << "\n1 Enqueue\n2 Dequeue\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> val;
            q.enqueue(val);
        }
        else if (ch == 2) q.dequeue();
        else if (ch == 3) cout << (q.isEmpty() ? "Empty\n" : "Not Empty\n");
        else if (ch == 4) cout << (q.isFull() ? "Full\n" : "Not Full\n");
        else if (ch == 5) q.display();
        else if (ch == 6) cout << q.peek() << endl;
        else if (ch == 7) break;
    }
}
