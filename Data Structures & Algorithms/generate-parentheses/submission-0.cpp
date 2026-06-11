class Solution {
public:
    bool isValid(string & str){
        int count = 0;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '('){
                count++;
            }else{
                count--;
            }

            if(count < 0) return false;
        }

        return count == 0;
    }

    void solve(string &curr, int n, vector<string>& result){
        if(curr.length() == 2* n){
            if(isValid(curr)){
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n, result);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n, result);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string curr = "";
        solve(curr, n, result);
        return result;
    }
};
