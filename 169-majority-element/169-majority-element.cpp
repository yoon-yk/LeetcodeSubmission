class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashM;
        int maxN = -1, freqN = -1;
        for (int n:nums){
            if (++hashM[n] > maxN) {
                maxN = hashM[n];
                freqN = n;
            }
        }
        return freqN;
    }
};