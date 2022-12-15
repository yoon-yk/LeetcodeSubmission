class Solution {
public:
    /*
    [1,2,3]
    [1,4,6]
    [2,5,7]
    
    [3,5,7]
    
    */
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> cand = {INT_MIN, INT_MIN, INT_MIN};
        for (auto & t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                cand[0] = max(cand[0], t[0]);
                cand[1] = max(cand[1], t[1]);
                cand[2] = max(cand[2], t[2]);
            }
        } 
        return (cand == target);
    }
};