class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currString = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(currString);

                num = 0;
                currString = "";
            }

            else if (ch == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                while (repeat--) {
                    prev += currString;
                }

                currString = prev;
            }

            else {
                currString += ch;
            }
        }

        return currString;
    }
};