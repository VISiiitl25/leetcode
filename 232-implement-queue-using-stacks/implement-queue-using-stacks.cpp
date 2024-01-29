#include <stack>

class MyQueue {
public:
    std::stack<int> st;

    MyQueue() {
    }

    void push(int x) {
        st.push(x);
    }

    int pop() {
        if (st.empty()) {
            // Handle empty queue case
            return -1; // You can choose a different value or throw an exception
        }

        std::stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        int x = temp.top();
        temp.pop();

        // Restoring the original stack
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return x;
    }

    int peek() {
        if (st.empty()) {
            // Handle empty queue case
            return -1; // You can choose a different value or throw an exception
        }

        std::stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        int x = temp.top();

        // Restoring the original stack
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return x;
    }

    bool empty() {
        return st.empty();
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
