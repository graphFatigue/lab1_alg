#include <iostream>

using namespace std;

class SortedLinkedList {
private:
    struct Node {
        int value;
        Node* next;
    };
    Node* head;

public:
    SortedLinkedList() {
        head = NULL;
    }

    void addElement(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* curr = head;
            Node* prev = NULL;
            while (curr != NULL && curr->value < value) {
                prev = curr;
                curr = curr->next;
            }
            if (prev == NULL) {
                head = newNode;
            }
            else {
                prev->next = newNode;
            }
            newNode->next = curr;
        }
    }

    void printElements() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void removeByIndex(int index) {
        if (head == NULL) {
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        int i = 0;
        while (i < index && curr != NULL) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (curr == NULL) {
            return;
        }
        if (prev == NULL) {
            head = curr->next;
        }
        else {
            prev->next = curr->next;
        }
        delete curr;
    }

    void removeByValue(int value) {
        if (head == NULL) {
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && curr->value != value) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            return;
        }
        if (prev == NULL) {
            head = curr->next;
        }
        else {
            prev->next = curr->next;
        }
        delete curr;
    }
};

int main() {
    SortedLinkedList list; // create an instance of the class

    // add elements to the list
    list.addElement(3);
    list.addElement(1);
    list.addElement(4);
    list.addElement(2);

    // print the elements of the list
    list.printElements(); // output: 1 2 3 4

    // remove an element by index
    list.removeByIndex(2); // remove the element at index 2 (value 3)
    list.printElements(); // output: 1 2 4

    // remove an element by value
    list.removeByValue(2); // remove the element with value 2
    list.printElements(); // output: 1 4

    return 0;
}

