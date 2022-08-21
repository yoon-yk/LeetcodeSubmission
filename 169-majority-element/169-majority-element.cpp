class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, cand = -1;
        for (int n:nums) {
            if (cnt == 0)
                cand = n;
            if (cand == n) cnt ++;
            else cnt--;
        }
        return cand;
    }
};