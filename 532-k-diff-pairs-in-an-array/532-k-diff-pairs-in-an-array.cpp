class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        /*
        
        1 3 4 5
        2 1 1 1
        
        */
        
        // 1. Insert all elems; O(N)
        unordered_map<int, int> hashM;
        for (auto next:nums) {
            if (hashM.find(next)==hashM.end())
                hashM[next] = 1;
            else hashM[next]++;
        }
        
        // 2. Iterate to find the; O(N) + 
        int ans = 0;
        for (auto num:hashM) {
            if (k==0){
                if (num.second > 1)
                    ans ++;
            }
            else {
                if (hashM.find(num.first+k)!=hashM.end()) 
                    ans ++;
            }
        }
        
        return ans;
    }
};