class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> startsWith;
        unordered_map<int, int> endsWith;
        
        for (int& n:nums) {
            startsWith[n]++;
        }
        
        for (int& n:nums) {
            if (startsWith[n] <= 0) continue;
            startsWith[n]--;
            
            if (endsWith[n-1] > 0) {
                endsWith[n-1]--;
                endsWith[n]++;
            }
            else if (startsWith[n+1] > 0 && startsWith[n+2] > 0) {
                startsWith[n+1]--;
                startsWith[n+2]--;
                endsWith[n+2]++;
            } 
            else return false;
        }
        
        return true;
        
    }
};