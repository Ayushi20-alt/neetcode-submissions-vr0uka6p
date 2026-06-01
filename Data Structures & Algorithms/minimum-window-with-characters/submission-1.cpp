class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int l = 0, r = 0, minLen = INT_MAX, sInd = -1, cnt = 0;

        for(int i = 0; i < t.size(); i++){
            hash[t[i]]++;
        }

        while(r < s.size()){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sInd = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sInd == -1 ? "" : s.substr(sInd, minLen);
    }
};
