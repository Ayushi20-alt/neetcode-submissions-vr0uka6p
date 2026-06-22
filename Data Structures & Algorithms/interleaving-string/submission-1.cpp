class Solution {
public:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3,int t[101][101][201]){
        int m = s1.size();
        int n = s2.size();
        int N = s3.size();

        if(i == m && j == n && k == N) return true;
        if(k >= N) return false;

        if(t[i][j][k] != -1) return t[i][j][k];

        bool result = false;

        if(i < m && s1[i] == s3[k]) result = solve(i+1, j, k+1, s1, s2, s3, t);
        if(result == true) return result;
        if(j < n && s2[j] == s3[k]) result = solve(i, j+1, k+1, s1, s2, s3, t);

        return t[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int t[101][101][201];

        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++)
                for(int k = 0; k < 201; k++)
                    t[i][j][k] = -1;
        return solve(0, 0, 0, s1, s2, s3, t);
    }
};
