class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        vector<int> len(k, 0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        if (*max_element(nums.begin(), nums.end()) > (sum / k)) return false;
        int target = (sum / k);
        sort(nums.begin(), nums.end(), greater<int>());
        // for (int n : nums) cout << n << " ";
        // cout << endl;
        // cout << target << endl;
        
        // return false;
        return backtrack(nums, len, 0, target, k);
    }
    
    bool backtrack(vector<int>& nums, vector<int>& len, int idx, int target, int curLeft) {

        if (idx == nums.size()) {

//             for (int n : len) cout << n << " ";
//             cout << endl;
            
            return (curLeft == 0);

        }        
            
        for (int i=0; i<len.size(); i++) {
            if (len[i] + nums[idx] > target)
                continue;
            int j = i-1;
            while (--j >= 0) if (len[i] == len[j]) break;
            if (j > -1) continue;
            
            len[i] += nums[idx];
            if (len[i] == target) curLeft --;
            if (backtrack(nums, len, idx+1, target, curLeft)) return true;
            if (len[i] == target) curLeft ++;
            len[i] -= nums[idx];
        }
        return false;
    }
};