#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/implement-queue-using-stacks/?envType=problem-list-v2&envId=rab78cw1

class MyQueue {
    stack<int> left;
    stack<int> right;
    int top = 0;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!right.empty()) {
            left.push(right.top());
            right.pop();
        }
        if(left.empty())
            top = x;
        left.push(x);
    }
    
    int pop() {
        while(!left.empty()) {
            right.push(left.top());
            left.pop();
        }
        int val = right.top();
        right.pop();
        if(!right.empty())
            top = right.top();
        return val;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return left.empty() && right.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main()
{
    cout << "begin"<< endl;
    {
    MyQueue sol;
    sol.push(1);
    assert(1 == sol.pop());
    assert(true == sol.empty());
    }
    {
    MyQueue sol;
    sol.push(1);
    sol.push(2);
    assert(1 == sol.peek());
    sol.pop();
    assert(2 == sol.peek());
    }
    cout << "end"<< endl;
    return 0;
}
