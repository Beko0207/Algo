#include <iostream>

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    
    DoublyLinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);
    
    if (!head) {
        return new_node;
    }
    
    if (data <= head->data) {
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }
    
    DoublyLinkedListNode* current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    
    new_node->next = current->next;
    new_node->prev = current;
    
    if (current->next) {
        current->next->prev = new_node;
    }
    
    current->next = new_node;
    
    return head;
}

void printList(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    DoublyLinkedListNode* head = nullptr;
    head = sortedInsert(head, 10);
    head = sortedInsert(head,11);
    head = sortedInsert(head, 12);
    head = sortedInsert(head, 13);
    
    printList(head);  // Выводит "1 2 3 4"
    
    return 0;
}