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
        unordered_map<string, function<int (int, int)>> mp = {
                {"+" , [](int a, int b){return a +b;}},
                {"-" , [](int a, int b){return b-a;}},
                {"*", [](int a, int b) {return a * b;}},
                {"/", [](int a, int b){return b/ a;}}
        };

        for(string& token : tokens){
            if(token == "+" || token == "*" || token == "/" || token == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = mp[token](a, b);
                st.push(res);
            }else st.push(stoi(token));
        }

        return st.top();
    }
};
