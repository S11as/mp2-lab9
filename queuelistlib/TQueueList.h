//
// Created by Kirill on 11/29/2020.
//

#ifndef QUEUELISTLIB_TQUEUELIST_H
#define QUEUELISTLIB_TQUEUELIST_H
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "TList.h"

using namespace std;
template <class T>
class TQueueList {
protected:
    TList<T> list;
public:
    TQueueList()  = default;

    TQueueList(TQueueList<T> &queue);
    TQueueList(TList<T> &queue);


    ~TQueueList() = default;

    TQueueList<T> &operator=(const TQueueList<T> &queue);

    void push(T item);

    T pop();

    bool is_empty();

    bool is_full();

    T get_max();

    T get_least();

    template<class T1>
    friend istream &operator>>(istream &istream, TQueueList<T1> &queue);

    template<class T1>
    friend ostream &operator<<(ostream &ostream, const TQueueList<T1> &queue);

    static TQueueList<T> &load(const char *name);

    void save(const char *name);
};

template<class T>
TQueueList<T>::TQueueList(TQueueList<T> &queue) {
    this->list = queue.list;
}

template<class T>
TQueueList<T>::TQueueList(TList<T> &list) {
    this->list = list;
}

template<class T>
TQueueList<T> &TQueueList<T>::operator=(const TQueueList<T> &queue) {
    if(this == &queue){
        return *this;
    }
    this->list = queue.list;
    return *this;
}

template<class T>
void TQueueList<T>::push(T item) {
    if(this->list.IsFull()){
        throw std::overflow_error("Queue is full");
    }
    this->list.InsLast(item);
}

template<class T>
T TQueueList<T>::pop() {
    if(this->list.IsEmpty()){
        throw std::range_error("Queue is empty");
    }
    T tmp = this->list.GetFirst()->GetData();
    this->list.DelFirst();
    return tmp;
}

template<class T>
bool TQueueList<T>::is_empty() {
    return this->list.IsEmpty();
}

template<class T>
bool TQueueList<T>::is_full() {
    return this->list.IsFull();
}

template<class T>
T TQueueList<T>::get_max() {
    if (this->list.IsEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T max = this->list.GetFirst()->GetData();
    for (auto elem : this->list) {
        if (elem > max) {
            max = elem;
        }
    }
    return max;
}

template<class T>
T TQueueList<T>::get_least() {
    if (this->list.IsEmpty()) {
        throw std::out_of_range("stack is empty");
    }
    T least = this->list.GetFirst()->GetData();
    for (auto elem : this->list) {
        if (elem < least) {
            least = elem;
        }
    }
    return least;
}

template<class T1>
istream &operator>>(istream &istream, TQueueList<T1> &queue) {
    return istream >> queue.list;
}

template<class T1>
ostream &operator<<(ostream &ostream, const TQueueList<T1> &queue) {
    return ostream << queue.list;
}

template<class T>
TQueueList<T> &TQueueList<T>::load(const char *name) {
    TList<T> list = TList<T>::load(name);
    auto* queue = new TQueueList(list);
    return *queue;
}

template<class T>
void TQueueList<T>::save(const char *name) {
    this->list.save(name);
}




#endif //QUEUELISTLIB_TQUEUELIST_H
