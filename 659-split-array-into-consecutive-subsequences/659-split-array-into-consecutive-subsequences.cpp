class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> head;
        unordered_map<int, int> tail;
        
        for (int& n:nums) {
            head[n]++;
        }
        
        for (int& n:nums) {
            if (head[n] <= 0) continue;
            head[n]--;
            
            if (tail[n-1] > 0) {
                tail[n-1]--;
                tail[n]++;
            }
            else if (head[n+1] > 0 && head[n+2] > 0) {
                head[n+1]--;
                head[n+2]--;
                tail[n+2]++;
            } 
            else return false;
        }
        
        return true;
        
    }
};