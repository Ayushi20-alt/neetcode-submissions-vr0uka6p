class Solution {
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3,int t[101][101]){
        int m = s1.size();
        int n = s2.size();
        int N = s3.size();

        if(i == m && j == n && i+j == N) return true;
        if(i+j >= N) return false;

        if(t[i][j] != -1) return t[i][j];

        bool result = false;

        if(i < m && s1[i] == s3[i+j]) result = solve(i+1, j, s1, s2, s3, t);
        if(result == true) return result;
        if(j < n && s2[j] == s3[i+j]) result = solve(i, j+1, s1, s2, s3, t);

        return t[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int t[101][101];

        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++)
                    t[i][j] = -1;
        return solve(0, 0, s1, s2, s3, t);
    }
};
