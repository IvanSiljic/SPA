#include "iostream"
#include "stack"
#include "queue"

using namespace std;

template <typename T>
class myQueue {
private:
    stack<T> firstStack;
    stack<T> secondStack;
public:
    unsigned int size() {
        return firstStack.size() + secondStack.size();
    }

    bool empty() {
        return size() == 0;
    }

    void push(T n) {
        firstStack.push(n);
    }

    void pop();
    T front();
};

template <typename T>
void myQueue<T>::pop() {
    if (empty())
        return;

    if (!secondStack.empty()) {
        secondStack.pop();
        return;
    }

    while (!firstStack.empty()) {
        secondStack.push(firstStack.top());
        firstStack.pop();
    }
}

template <typename T>
T myQueue<T>::front() {
    if (!secondStack.empty())
        return secondStack.top();

    while (!firstStack.empty()) {
        secondStack.push(firstStack.top());
        firstStack.pop();
    }

    return secondStack.top();
}

int main() {
    myQueue<int> queue1;
    int i = 0;

    while (i < 50) {
        queue1.push(i);
        i++;
    }

    cout << queue1.front() << " " << endl;
    queue1.pop();

    cout << queue1.front() << endl;

    return 0;
}