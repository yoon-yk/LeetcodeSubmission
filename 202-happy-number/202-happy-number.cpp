class Solution {
public:
    bool isHappy(int n) {
        
        int sum = 0, digit;
        unordered_map<int, int> hashM;
        
        while (1) {
            
            sum = 0;
            while (n > 0) {
                digit = (n % 10);
                sum += digit*digit;
                n = n/10;
            }
            if (sum == 1) return true;
            if (hashM.find(sum) != hashM.end()) {
                return false;
            }
            else {
                hashM[sum] += 1;
                n = sum;
            }
            
        }
        return false;
    }
};