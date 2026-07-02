class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string s = "";

        while(i < word1.size() && j < word2.size()){
            s.push_back(word1[i]);
            i++;
            s.push_back(word2[j]);
            j++;
        }

        while(i < word1.size()) {
            s.push_back(word1[i]);
            i++;
        }

        while(j < word2.size()) {
            s.push_back(word2[j]);
            j++;
        }

        return s;
    }
};