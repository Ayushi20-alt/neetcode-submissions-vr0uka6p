class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first = false, second = false, third = false;

        for(auto &triplet : triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]){
                continue;
            }
            if(triplet[0] == target[0]) first = true;
            if(triplet[1] == target[1]) second = true;
            if(triplet[2] == target[2]) third = true;
        }

        return first && second && third;
    }
};
