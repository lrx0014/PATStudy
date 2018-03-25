class MinStack {
public:
    stack<int> origin;
    stack<int> minums;
    void push(int value) {
        origin.push(value);
        if(minums.empty() || value<minums.top())
        {
            minums.push(value);
        }
        else
        {
            minums.push(minums.top());
        }
    }
    void pop() {
        origin.pop();
        minums.pop();
    }
    int top() {
        return origin.top();
    }
    int min() {
        return minums.top();
    }
};