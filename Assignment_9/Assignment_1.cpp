#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (elements.empty())
            throw out_of_range("Stack<>::pop(): empty stack");
        elements.pop_back();
    }

    T& top() {
        if (elements.empty())
            throw out_of_range("Stack<>::top(): empty stack");
        return elements.back();
    }

    const T& top() const {
        if (elements.empty())
            throw out_of_range("Stack<>::top(): empty stack");
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

class Box {
public:
    Box(int length, int width, int height) : length(length), width(width), height(height) {}

    int getVolume() const {
        return length * width * height;
    }

private:
    int length;
    int width;
    int height;
};

int main() {
    // Test Stack<int>
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    cout << "Size of intStack: " << intStack.size() << endl;
    cout << "Top element of intStack: " << intStack.top() << endl;
    intStack.pop();
    cout << "Top element after pop: " << intStack.top() << endl;

    // Test Stack<double>
    Stack<double> doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);
    cout << "Size of doubleStack: " << doubleStack.size() << endl;
    cout << "Top element of doubleStack: " << doubleStack.top() << endl;
    doubleStack.pop();
    cout << "Top element after pop: " << doubleStack.top() << endl;

    // Test Stack<Box>
    Stack<Box> boxStack;
    boxStack.push(Box(1, 2, 3));
    boxStack.push(Box(2, 3, 4));
    boxStack.push(Box(3, 4, 5));
    cout << "Size of boxStack: " << boxStack.size() << endl;
    cout << "Volume of top box: " << boxStack.top().getVolume() << endl;
    boxStack.pop();
    cout << "Volume of top box after pop: " << boxStack.top().getVolume() << endl;

    return 0;
}
