class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort n krna pade to hum unko vector of size 26 m rakhege aur 
        // traverse krege usse sorted bach jayega
        int n = strs.size();
        unordered_map<string, vector<string>>mpp;
        vector<vector<string>>result;

        for(int i = 0; i < n; i++){
            string s = strs[i];
            string new_word = generate(s);
            mpp[new_word].push_back(s);
        }

        for(auto &it : mpp){
            result.push_back(it.second);
        }
        return result;
    }

    string generate(string& word){
        int arr[26] = {0};

        for(char &ch: word){
            arr[ch - 'a']++;
        }

        string new_word = "";
        for(int i = 0; i < 26; i++){
            int freq = arr[i];
            if(freq > 0) {
                new_word += string(freq, i + 'a');
            }
        }
        return new_word;
    }
};