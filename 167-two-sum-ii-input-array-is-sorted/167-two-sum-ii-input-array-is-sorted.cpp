class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashM;
        int cand;
        
        for (int i=0; i<numbers.size(); i++) 
            hashM[numbers[i]] = i+1;
        
        for (int i=0; i<numbers.size(); i++) {
            cand = target - numbers[i];
            if(hashM.find(cand)!=hashM.end()) 
                return {i+1, hashM[cand]};
        }
        
        return {};
    }
};