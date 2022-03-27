class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;

        unordered_map<int,int> hashT; 
        int minN = INT_MAX, maxN = INT_MIN;
        
        for (int i:nums) {
            hashT[i] ++;
            minN = min(minN, i);
            maxN = max(maxN, i);
        }
        
        int cnt = 1, curN, maxCnt = 1;
        
        for (auto num:hashT) {
            if (hashT.find(num.first-1)==hashT.end()){
                cnt = 1;
                curN = num.first;
                while (hashT.find(curN+1)!=hashT.end()) {
                    cnt ++; curN ++;
                    maxCnt = max(maxCnt, cnt);
                }
            } 
        }
        
        return maxCnt;
    }
};