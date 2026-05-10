class Solution {
public:
    int Operate(int &a, int &b, string &token){
        if(token == "+") return a + b;
        if(token == "-") return b - a;
        if(token == "*") return a * b;
        if(token == "/") return b / a;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(string& token : tokens){
            if(token == "+" || token == "*" || token == "/" || token == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = Operate(a, b, token);
                st.push(res);
            }else st.push(stoi(token));
        }

        return st.top();
    }
};
