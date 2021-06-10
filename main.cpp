#include <iostream>
#include "Stack.h"
using namespace std;


const char *msg1[] = {"0. Quit",
                      "1. Push item",
                      "2. Pop item",
                      "3. Look at the top item",
                      "4. Check if the stack is empty"};

const char *msg2[] = {"0. Quit", "1. Int", "2. Float"};

template<int N>
int dialog(const char *(&msgs)[N]) {
    int choice;
    for (int i = 0; i < N; ++i)
        cout << msgs[i] << endl;
    cout << "Make your choice: \n";
    cin >> choice;
    return choice;
}


template <typename T>
void UI() {
    int res = 1;
    Stack<T> stack;
    while (res != 0) {
        res = dialog(msg1);
        switch (res) {
            case 0:
                break;
            case 1: {
                T item = 1;
                cout << "Enter a value: ";
                cin >> item;
                stack.Push(item);
                break;
            }
            case 2:
                stack.Pop();
                break;
            case 3:
                cout << stack.Top() << endl;
                break;
            case 4:
                if (stack.isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;
            default:
                break;
        }
    }
}

int f(int x1, int x2) {
    return 2*x1 + 3*x2;
}
int main() {
    int res;
    cout << "Enter data type: ";
    res = dialog(msg2);
    switch (res) {
        case 0:
            break;
        case 1:
            UI<int>();
            break;
        case 2:
            UI<float>();
            break;
        default:
            break;
    }


    return 0;
}
