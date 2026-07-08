#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    // Insert at beginning
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at index
    void push_index(int index, int val) {

        if (index == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid Index" << endl;
            return;
        }

        if (temp == tail) {
            push_back(val);
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Print list
    void print() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    DoublyList ddl;

    ddl.push_index(0, 10);   // 10
    ddl.push_back(20);       // 10 20
    ddl.push_back(30);       // 10 20 30
    ddl.push_index(1, 15);   // 10 15 20 30
    ddl.push_index(3, 25);   // 10 15 20 25 30

    ddl.print();

    return 0;
}