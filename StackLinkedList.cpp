#include <iostream>
    using namespace std;

    class Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    class Stack {
    public:
        Node* top;
        Stack() : top(NULL) {}

        void push(int val) {
            Node* newNode = new Node(val);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (!top) return;
            Node* del = top;
            top = top->next;
            delete del;
        }

        void display() {
            Node* temp = top;
            while (temp) { cout << temp->data << " "; temp = temp->next; }
            cout << endl;
        }
    };

    int main() {
        Stack st;
        st.push(10);
        st.push(20);
        st.push(30);
        st.display();
        st.pop();
        st.display();
    }
    