class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int l = 0;
        int r = 0;

        while(l < s.size() && r < t.size()){
            if(s[l] != t[r]){
                return false;
            }
            l++;
            r++;
        }
        return true;
    }
};
