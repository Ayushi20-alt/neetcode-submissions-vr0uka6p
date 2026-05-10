class MinStack {
    stack<long long> st;
    long long minVal;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        } else {
            if (val >= minVal) {
                st.push(val);
            } else {
                st.push(2LL * val - minVal);  // encode
                minVal = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() >= minVal) {
            st.pop();
        } else {
            minVal = 2LL * minVal - st.top(); // decode
            st.pop();
        }
    }

    int top() {
        if (st.top() >= minVal) return st.top();
        return minVal;
    }

    int getMin() {
        return minVal;
    }
};