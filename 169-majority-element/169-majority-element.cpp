class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashM;
        int targetFreq = nums.size() >> 1;
        int maxN = -1, freqN = -1;
        for (int n:nums){
            if (++hashM[n] > targetFreq) {
                freqN = n;
                break;
            }
        }
        return freqN;
    }
};