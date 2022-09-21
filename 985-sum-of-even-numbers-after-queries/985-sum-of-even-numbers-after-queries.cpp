class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // hash table; idx : boolean value (true or false)
        // evenSum - initialize with the even sum of the initial nums array
        // every time i get queries, i will update hash table if it's even or odd, 
        // even -> even, add the difference 
        // odd -> even, add the value 
        // even -> odd -> deduct the nums[idx] from the sum
        
        // odd -> odd -> continue
        
        int curSum = 0;
        vector<int> isEven(nums.size(), false);
        vector<int> ans;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 == 0) { // even
                isEven[i] = true;
                curSum += nums[i];
            }
        }
        
        int curN, newN;
        for (vector<int> & q : queries) {
            // q[0] - val, q[1] - index
            curN = nums[q[1]], newN = nums[q[1]] + q[0];
            nums[q[1]] = newN;
            
            if (curN % 2 == 0) { // cur N == even
                if (newN % 2 == 0) { // new N == even
                    curSum += (newN - curN);
                } else { // new N == odd
                    curSum -= curN;
                    isEven[q[1]] = false;
                }
            }
            else { // cur N == odd 
                if (newN % 2 == 0) { // new N == even
                    curSum += newN;
                    isEven[q[1]] = true;
                } 
            }
            
            ans.push_back(curSum);
        }
        
        return ans; 
    }
};