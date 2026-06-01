class Solution {
public:
    int characterReplacement(string s, int k) {
        // length - max freq is the letters that can be changed
        int maxLen = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            int hash[26] = {0};
            int maxfreq = 0;
            for(int j = i; j < n; j++){
                 hash[s[j] - 'A']++;;
                maxfreq = max(maxfreq, hash[s[j] - 'A']);
                int changes = (j-i+1) - maxfreq;
                if(changes <= k){
                    maxLen = max(maxLen , j-i+1);
                }else{
                    break;
                }
            }
        }

        return maxLen;
    }
};
