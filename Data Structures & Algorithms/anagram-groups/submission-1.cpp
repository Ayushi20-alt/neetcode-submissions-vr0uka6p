class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>vec;
        unordered_map<string, vector<string>>mpp;

        for(int i = 0; i < strs.size(); i ++){
            string s = strs[i];
            sort(s.begin(), s.end()); // k*logk*n
            mpp[s].push_back(strs[i]);
        }

        for(auto it : mpp){
            vec.push_back(it.second);
        }
        return vec;
    }
};
