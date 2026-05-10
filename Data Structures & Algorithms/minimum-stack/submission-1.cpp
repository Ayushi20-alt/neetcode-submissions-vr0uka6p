class MinStack {
    stack<pair<int, int>>st;
public:
    MinStack() {
        // T.C = O(1)
        // S.C = O(2*n)
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }else{
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top() {
        if(!st.empty()) return st.top().first;
        else return -1;
    }
    
    int getMin() {
        if(!st.empty()) return st.top().second;
        else return -1;
    }
};
