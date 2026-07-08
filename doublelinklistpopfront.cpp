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

    // Delete first node
    void pop_front() {

        if (head == NULL) {
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;

        head = head->next;
        head->prev = NULL;

        delete temp;
    }

    // Delete last node
    void pop_back() {

        if (head == NULL) {
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = tail;

        tail = tail->prev;
        tail->next = NULL;

        delete temp;
    }

    // Print list
    void print() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {

    DoublyList ddl;

    ddl.push_front(20);
    ddl.push_front(10);

    ddl.push_back(30);
    ddl.push_back(40);

    ddl.push_index(2, 25);

    cout << "Initial List:\n";
    ddl.print();

    ddl.pop_front();

    cout << "\nAfter pop_front():\n";
    ddl.print();

    ddl.pop_back();

    cout << "\nAfter pop_back():\n";
    ddl.print();

    return 0;
}