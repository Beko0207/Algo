#include <iostream>

class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int _val) : val(_val), next(nullptr) {}
    };

    MyLinkedList() : head(nullptr) {}

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

private:
    Node* head;
};

int main() {
    MyLinkedList linkedList;

    linkedList.addAtHead(3);
    linkedList.addAtHead(2);
    linkedList.addAtHead(1);

    std::cout << "Original List: ";
    linkedList.print();

    linkedList.reverse();

    std::cout << "Reversed List: ";
    linkedList.print();

    return 0;
}