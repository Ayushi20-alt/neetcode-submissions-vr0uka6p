class Solution {
public:
    bool isPalin(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
    void findPartition(string s, vector<string>& vec, vector<vector<string>>& ans){
        if(s.size() == 0){
            ans.push_back(vec);
            return;
        }

        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i+1);

            if(isPalin(part)){
                vec.push_back(part);
                findPartition(s.substr(i+1), vec, ans);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>vec;
        findPartition(s, vec, ans);
        return ans;
    }
};