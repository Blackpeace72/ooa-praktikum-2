//
// Created by Felix Häner on 3.05.2019.
//

#include <string>

class PriorityQueue{
    friend class Knoten;
private:
    int _size;
    class Knoten * _head;
    class Knoten * _tail;
    bool isEmpty();

public:
    PriorityQueue();
    ~PriorityQueue();
    void insert(std::string value, float priority);
    std::string extractMin(void);
    void decreaseKey(std::string value, float priority);
    void remove(std::string value);
    void testdecrease();
    void testremove();
};

class Knoten{ //public   private------
    friend class PriorityQueue;
private:
    float _priority;
    std::string _value;
    class Knoten * _next;
    class Knoten * _prev;
public:
    Knoten();
    ~Knoten();
};
