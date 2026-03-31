class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        
        for (const string& str : strs) {
            res += to_string(str.size()) + "#" + str;
        }
        
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        for (int i = 0; i < s.size(); ) {
            
            // Parse length
            int length = 0;
            while (s[i] != '#') {
                length = length * 10 + (s[i] - '0');
                i++;
            }
            
            i++; // skip '#'
            
            // Extract string
            result.push_back(s.substr(i, length));
            
            i += length; // move forward
        }
        
        return result;
    }
};
