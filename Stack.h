#ifndef LAB2_STACK_H
#define LAB2_STACK_H

#include "ArraySequence.h"
#include "ListSequence.h"

template <class T>
class Stack {
private:
    Sequence<T> *data;
public:

    Stack() {
        this->data = new ListSequence<T>();
    }

    Stack(Sequence<T> *data) {
        this->data = data;
    }

    void Push(T item) {
        this->data->Prepend(item);
    }

    T &Pop() {
        T temp = this->data->GetFirst();
        this->data->PopFirst();
        return temp;
    }

    T &Top() {
        return this->data->GetFirst();
    }

    bool isEmpty() {
        return this->data->GetLength() == 0;
    }
};

#endif



