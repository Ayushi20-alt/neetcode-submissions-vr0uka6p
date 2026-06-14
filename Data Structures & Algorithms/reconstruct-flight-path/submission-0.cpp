class Solution {
public:
    bool Dfs(string fromAirport, vector<string>&path, unordered_map<string, vector<string>>&adj, 
    int n, vector<string>& result){
        path.push_back(fromAirport);

        if(path.size() == n+1){
            result = path;
            return true;
        }

        vector<string>& neighbours = adj[fromAirport];
        for(int i = 0; i < neighbours.size(); i++){
            string toAirport = neighbours[i];
            // cycle se bachne ke liye abhi ke liye remove krdo
            neighbours.erase(neighbours.begin() + i);
            if(Dfs(toAirport, path, adj, n, result) == true) return true;
            neighbours.insert(neighbours.begin() + i, toAirport);
        }

        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       unordered_map<string, vector<string>>adj;
       vector<string>result;
       int n = tickets.size();

       for(auto &it : tickets){
            string to = it[0];
            string from = it[1];
            adj[to].push_back(from);
       }

       // sorting for lexicographical order
       for(auto &it : adj){
           sort(begin(it.second), end(it.second));
       }

       vector<string> path;
       Dfs("JFK" , path, adj, n, result);

       return path;
    }
};
