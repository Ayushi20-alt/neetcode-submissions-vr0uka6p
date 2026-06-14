class Solution {
private:
    vector<int> topoSort(int n, vector<int> adj[]) {
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {
            for(int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }
public:  
    string foreignDictionary(vector<string>& words) {
        vector<int> adj[26];
        vector<bool> present(26, false);

        // mark used chars
        for(auto &word : words) {
            for(char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            // invalid prefix case
            if(!found && s1.size() > s2.size())
                return "";
        }

        vector<int> topo = topoSort(26, adj);

        string ans = "";
        int uniqueChars = 0;

        for(int i = 0; i < 26; i++) {
            if(present[i]) uniqueChars++;
        }

        // build answer using only present chars
        for(int x : topo) {
            if(present[x])
                ans += char(x + 'a');
        }

        // cycle detection
        if(ans.size() != uniqueChars)
            return "";

        return ans;
    }
};