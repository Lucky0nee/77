#include <iostream>

using namespace std;
class Stack {
private:
    int* stackstore;
    int stacksize;
    int SP;
public:
    Stack(int size = 1000);
    ~Stack();
    void push(int value);
    int pop(void);
};
Stack::Stack(int size)
{
    try {
        if (size <= 0)
        {
            throw length_error("Розмір має бути більший нуля");
        }
        stackstore = new int[size];
        stacksize = size;
        SP = 0;
    }
    catch (length_error)
    {
        cout << "Розмір був заданий хибно, створення буде здійснено з наперед визначеними параметрами: розмір = 1000." << endl;
        stackstore = new int[1000];
        stacksize = 1000;
        SP = 0;
    }
    catch (bad_alloc)
    {
        cout << "Розмір був заданий занадто великий!" << endl;
        throw;
    }
}

Stack::~Stack() {
    delete[]stackstore;
}

void Stack::push(int value) {
    try {
        if (SP == stacksize)
        {
            throw logic_error("Стос заповнений.");
        }
        stackstore[SP++] = value;
    }
    catch (logic_error)
    {
        cout << "Не можливо додати новий елемент!" << endl;
    }
}
int Stack::pop() {
    try {
        if (SP == 0)
        {
            throw logic_error("Стос порожній.");
        }
        return stackstore[--SP];
    }
    catch (logic_error)
    {
        cout << "Нема що вилучити." << endl;
        SP = 0;
        throw;
    }
}
int main() {
    try {
        Stack stk(2100);
        try {
            stk.pop();
        }
        catch (logic_error)
        {
            cout << "Вилучення не здійснено." << endl;
        }
        stk.push(1);
        stk.push(2);
        stk.push(5);
        stk.push(7);
        stk.push(1);
        stk.push(2);
        stk.push(5);
        stk.push(7);
        stk.push(1);
        stk.push(2);
        stk.push(5);
        stk.push(7);
        try {
            cout << "Забрали: " << stk.pop() << "." << endl;
            cout << "Забрали: " << stk.pop() << "." << endl;
            cout << "Забрали: " << stk.pop() << "." << endl;
            cout << "Забрали: " << stk.pop() << "." << endl;
            cout << "Забрали: " << stk.pop() << "." << endl;
            cout << "Забрали: " << stk.pop() << "." << endl;
        }
        catch (logic_error)
        {
            cout << "Вилучення не здійснено." << endl;
        }
    }
    catch (logic_error)
    {
        cout << "Розміщення в пам'яті не відбулося." << endl;
    }
    return 0;
}
