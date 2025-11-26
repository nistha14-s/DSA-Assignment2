#include <iostream>
    using namespace std;

    class Node {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    class SinglyLinkedList {
    public:
        Node* head;
        SinglyLinkedList() : head(NULL) {}

        void insertNode(int val) {
            Node* newNode = new Node(val);
            if (!head) { head = newNode; return; }
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }

        void deleteNode(int val) {
            if (!head) return;
            if (head->data == val) {
                Node* del = head;
                head = head->next;
                delete del;
                return;
            }
            Node* temp = head;
            while (temp->next && temp->next->data != val)
                temp = temp->next;
            if (temp->next) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
        }

        void display() {
            Node* temp = head;
            while (temp) { cout << temp->data << " "; temp = temp->next; }
            cout << endl;
        }
    };

    int main() {
        SinglyLinkedList list;
        list.insertNode(10);
        list.insertNode(20);
        list.insertNode(30);
        list.display();
        list.deleteNode(20);
        list.display();
    }
    