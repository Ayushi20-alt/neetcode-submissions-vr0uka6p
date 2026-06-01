class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLen = INT_MAX, sIndex = -1;

        for(int i = 0; i < n; i++){
            int hash[256] = {0};
            int cnt = 0;
            for(int j = 0; j < m; j++) hash[t[j]]++;
            for(int j = i; j < n; j++){
                hash[s[j]]--;
                if(hash[s[j]] >= 0) cnt++;
                if(cnt == m){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        sIndex = i;
                        break;
                    }
                }
            }
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};
