class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for (auto n:nums)
            res.push_back(pow(n, 2));
        sort(res.begin(), res.end());
        return res;
    }
};