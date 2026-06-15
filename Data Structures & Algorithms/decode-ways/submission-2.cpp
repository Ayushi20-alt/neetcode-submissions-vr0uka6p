class Solution {
public:
    int solve(int i, string &s, vector<int>&dp){
        int n = s.size();
        if(i == n) return 1; // one valid split done
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int result = solve(i+1, s, dp);

        if(i + 1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) result += solve(i+2, s, dp);
        }

        return dp[i] = result;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size() + 1, -1);
        return solve(0, s, dp);
    }
};
