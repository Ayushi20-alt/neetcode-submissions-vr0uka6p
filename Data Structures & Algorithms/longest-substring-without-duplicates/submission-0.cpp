class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mpp;
        int l = 0;
        int maxi = 0;

        for(int r = 0; r < s.length(); r++){

            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                l = mpp[s[r]] + 1;
            }

            mpp[s[r]] = r;

            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};
