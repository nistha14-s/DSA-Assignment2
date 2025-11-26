#include <iostream>
    #include <stack>
    using namespace std;

    class Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    class LinkedList {
    public:
        Node* head;
        LinkedList() : head(NULL) {}

        void insert(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        void reverseUsingStack() {
            stack<int> st;
            Node* temp = head;
            while (temp) { st.push(temp->data); temp = temp->next; }
            temp = head;
            while (temp) { temp->data = st.top(); st.pop(); temp = temp->next; }
        }

        void display() {
            Node* temp = head;
            while (temp) { cout << temp->data << " "; temp = temp->next; }
            cout << endl;
        }
    };

    int main() {
        LinkedList list;
        list.insert(30);
        list.insert(20);
        list.insert(10);
        list.display();
        list.reverseUsingStack();
        list.display();
    }
    