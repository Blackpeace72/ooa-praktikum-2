//
// Created by Felix Häner on 3.05.2019.
//
using namespace std;
#include <iostream>
#include "pqueue.h"

Knoten::Knoten(){
}

Knoten::~Knoten() {
}

PriorityQueue::PriorityQueue(){
    _size = 0;
    _head = new Knoten;
    _tail = new Knoten;
    _head->_next = _tail;
    _head->_priority = NULL;
    _head->_value = '0';
    _tail->_priority = NULL;
    _tail->_value = '0';
    _tail->_prev = _head;
}

PriorityQueue::~PriorityQueue(){
    if(_size == NULL){
        if (_head != _tail){
            delete[] _head;
            delete[] _tail;
        }
        delete[] _head;
    }

    while (_size != 0){
        delete[] _head;
        _head = _head->_next;
        _size--;
    }
    delete[] _head;
    delete[] _tail;
}

bool PriorityQueue::isEmpty(){
    if(_size == 0) return true;
    return false;
}

void PriorityQueue::insert(std::string value, float priority){
    Knoten * search;
    Knoten * entry = new Knoten;
    Knoten * help;
    if(entry == NULL) EXIT_FAILURE;
    entry->_priority = priority;
    entry->_value = value;
    search = _head;

    while((search->_next != _tail) && (search->_next->_priority < priority))
        search = search->_next;
    //rechts von search einfügen
    help = search->_next;
    entry->_next = search->_next;
    entry->_prev = search;
    search->_next = entry;
    help->_prev = entry;
    _size++;
    return;
}

std::string PriorityQueue::extractMin(void){
    if(_size == 0){
        cout << "keine Werte zum ausgeben vorhanden";
        return NULL;
    }
    std::string ext = _head->_next->_value;
    Knoten * help;
    help = _head->_next->_next;
    _head->_next = help;
    help->_prev = _head;
    _size--;
    return ext;
}

void PriorityQueue::decreaseKey(std::string value, float priority){
    remove(value);
    insert(value, priority);
}

void PriorityQueue::remove(std::string value){
    if(_size == 0) return;
    Knoten * search;
    Knoten * searchprev;
    Knoten * searchnext;
    search = _head;
    while((search->_next != _tail) && (search->_value != value))
        search = search->_next;

    if(search->_value == value && (search != _head) && (search != _tail)){
        searchnext = search->_next;
        searchprev = search->_prev;
        searchprev->_next = searchnext;
        searchnext->_prev = searchprev;
        _size--;
        return;
    }
    cout << "Wert nicht vorhanden";
    return;
}

/*
void PriorityQueue::testremove() {
    Knoten * search;
    search = _head->_next;
    cout << "Test pqremove :\n";
    cout << "10 Eintraege vor remove: \n";
    for(int i = 0; i < 10; i++ ){
        cout << search->_value << "  " << search->_priority << endl;
        search = search->_next;
    }

    insert("ABCD", 28);
    search = _head->_next;

    cout << "11 Eintraege nach insert: \n";
    for(int i = 0; i < 11; i++ ){
        cout << search->_value << "  " << search->_priority << endl;
        search = search->_next;
    }

    remove("ABCD");
    search = _head->_next;

    cout << "10 Eintraege nach remove: \n";
    for(int i = 0; i < 10; i++ ){
        cout << search->_value << "  " << search->_priority << endl;
        search = search->_next;
    }
}

void PriorityQueue::testdecrease() {
    Knoten * search = new Knoten;
    search = _head->_next;
    cout << "Test deckey :\n";
    cout << "10 Eintraege vor deckey: \n";
    for(int i = 0; i < 10; i++ ){
        cout << search->_value << "  " << search->_priority << endl;
        search = search->_next;
    }

    insert("ABCD", 0);
    search = _head->_next;

    cout << "11 Eintraege nach insert: \n";
    for(int i = 0; i < 11; i++ ){
        cout << search->_value << "  " << search->_priority << endl;
        search = search->_next;
    }

    decreaseKey("ABCD", 100);
    search = _head->_next;

    cout << "11 Eintraege nach deckey: \n";
    for(int i = 0; i < 11; i++ ){
        cout << search->_value << "  " << search->_priority << endl;
        search = search->_next;
    }
    cout << "\n \n"<< endl;
}
*/