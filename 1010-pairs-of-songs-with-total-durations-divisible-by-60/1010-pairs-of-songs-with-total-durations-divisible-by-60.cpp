class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
    
        // (time[i] + time[j]) % 60 = 0
        // ((time[i] % 60) + (time[j] % 60)) % 60 = 0
        // (a + b) % 60 = 0
        // a%60 + b%60 = sum%60        
        // 150 150
        // 30 30 // 60-30 = 30
        // 149 151
        // 29 31 // 60-31 
        // 120 120
        // 0 0; 
        
        int kMins = 60, curLeft, target, ans = 0;
        vector<int> freq(kMins, 0);
        for (int i=0; i<time.size(); ++i) {
            curLeft = time[i] % kMins; // 0
            target = (kMins-curLeft) % kMins;  // 0
            ans += freq[target];
            
            ++freq[curLeft];
        }
        return ans;
    }
};