class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> min_vals;
    void push(int x)
    {
        if (min_vals.empty() || x <= min_vals.top())
        {
            min_vals.push(x);
        }
        s.push(x);
    }

    void pop()
    {
        if (s.top() == min_vals.top())
        {
            min_vals.pop();
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_vals.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */