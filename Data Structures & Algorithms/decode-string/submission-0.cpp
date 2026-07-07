class Solution {
public:
    string decodeString(string s) {

        stack<string> st;

        for (char ch : s) {

            if (ch != ']') {
                st.push(string(1, ch));
            }
            else {

                // Get encoded string
                string temp = "";

                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }

                st.pop(); // Remove '['

                // Get number
                string num = "";

                while (!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }

                int repeat = stoi(num);

                string expanded = "";
                while (repeat--) {
                    expanded += temp;
                }

                st.push(expanded);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};