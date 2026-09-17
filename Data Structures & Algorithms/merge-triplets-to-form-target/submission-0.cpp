class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> req;
        for(auto& i : triplets){ 
            if(i[0] <= target[0] && i[1] <= target[1] && i[2] <= target[2])
                req.push_back(i);
        }
        bool c0 = false , c1 = false , c2 = false;    
        for(auto& i : req){
            if(i[0] == target[0]) c0 = true;
            if(i[1] == target[1]) c1 = true;
            if(i[2] == target[2]) c2 = true;
        }

        return c0 && c1 && c2;
    }
};