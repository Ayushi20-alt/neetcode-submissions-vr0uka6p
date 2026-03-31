class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[26] = {0};
        int seq = 0;

        for(int i = 0; i < order.size(); i++){
            arr[order[i] - 'a'] = seq++;
        }

        for(int i = 0; i < words.size()-1; i++){
            string curr = words[i];
            string next = words[i+1];

            int len = min(curr.size(), next.size());

            if(curr.size() > next.size() && curr.substr(0, len) == next){
                return false;
            }

            for(int j = 0; j < len ; j++){
                if(arr[curr[j] - 'a'] > arr[next[j]-'a']){
                    return false;
                }
                if(arr[curr[j] - 'a'] < arr[next[j]-'a']){
                    break;
                }
            }
        }

        return true;
    }
};