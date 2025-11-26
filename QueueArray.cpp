#include <iostream>
    using namespace std;

    class Queue {
    public:
        int arr[100], front, rear;

        Queue() : front(0), rear(0) {}

        void enqueue(int val) {
            arr[rear++] = val;
        }

        void dequeue() {
            if (front == rear) return;
            front++;
        }

        void display() {
            for (int i = front; i < rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    };

    int main() {
        Queue q;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.display();
        q.dequeue();
        q.display();
    }
    