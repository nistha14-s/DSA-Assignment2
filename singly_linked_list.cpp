#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(NULL) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteVal(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;
        if (temp->next) {
            Node* tmp = temp->next;
            temp->next = temp->next->next;
            delete tmp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "List: ";
    list.display();

    list.deleteVal(20);
    cout << "After deletion: ";
    list.display();
}
