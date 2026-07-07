class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       vector<int>ans;

       for(int it : asteroids){
           if(it > 0) ans.push_back(it);
           else{
               while(!ans.empty() && ans.back() > 0 && ans.back() < abs(it)){
                   // if list has smaller element just remove it
                   ans.pop_back();
               }
               if(!ans.empty() && ans.back() == abs(it)) ans.pop_back();
               else if(ans.empty() || ans.back() < 0){
                   ans.push_back(it);
               } 
           }
       } 

       return ans;
    }
};