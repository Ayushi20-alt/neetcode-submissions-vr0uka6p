class TimeMap {
    unordered_map<string, vector<pair<int, string>>>mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end()) return "";

        auto &arr = mpp[key];
        int n = arr.size();

        int lo = -1;
        int hi = n;
        while(lo + 1 < hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid].first <= timestamp){
                lo = mid;
            }else{
                hi = mid;
            }
        }

        if(lo == -1) return "";
        return arr[lo].second;
    }
};
