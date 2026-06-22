#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

    void fillOutput()
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }
public:
    MyQueue(){}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty())
        {
            fillOutput();
        }

        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty())
        {
            fillOutput();
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};