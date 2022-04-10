/*
[2, 3, 6, 7]
target = 7

[2] -> (7-2) = 5 -> (5-2) = 3 -> 3
[3] -> (7-3) = 4 -> (4-2) = 2 -> 2
[6] -> (7-6) = 1
[7] -> (7-7) = 0



                [2]                []
        [2,2]           [2]     [3]   []
    [2,2,2] [2,2,3]  []


*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        dfs(0, target, 0, candidates, {}, res);
        return res;
    }
    
    void dfs(int index, int target, int sum, vector<int> candidates, vector<int> comb, vector<vector<int>>& res) {
        if (sum > target || index >= candidates.size()) return;
        if (sum  == target) {
            res.push_back(comb); 
            return;
        }
        
        // exclude current index
        dfs(index+1, target, sum, candidates, comb, res);  
        
        // include current index
        comb.push_back(candidates[index]);
        sum += candidates[index];
        dfs(index, target, sum, candidates, comb, res);
    }
        
};