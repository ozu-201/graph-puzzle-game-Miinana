//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "EdgeList.h"
//costtructor
EdgeList::EdgeList() {
    head = nullptr;
    tail = nullptr;
}
//descructor
EdgeList::~EdgeList() {
    Edge *tmp = head;
    Edge *next;
    while (tmp != nullptr) {
        next = tmp->getNext();
        delete tmp;
        tmp = next;
    }
}
//check ıf the edge lıst ıs empty
bool EdgeList::isEmpty() const {
    return head == nullptr;
}
//search for an edge in list
Edge *EdgeList::search(int to) const{
    Edge* tmp = head;
    //search for edge lıst wıth the value
    while (tmp != nullptr) {
        if (to == tmp->getTo()) {
            return tmp;
        }
        tmp = tmp->getNext();
    }
    return nullptr; //return null ıf ıt ıs empty
}
// Insert a new edge to the list
void EdgeList::insert(Edge *newEdge) {
    if (head == nullptr) {
        head = newEdge;
    } else {
        tail->setNext(newEdge);
    }
    tail = newEdge;
}
//get head
Edge *EdgeList::getHead() {
    return head;
}
