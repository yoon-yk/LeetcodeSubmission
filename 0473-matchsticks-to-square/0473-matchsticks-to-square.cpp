class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        
        vector<int> len(4, 0);
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;
        if (*max_element(matchsticks.begin(), matchsticks.end()) > (sum >> 2)) return false;
        int target = (sum >> 2);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return backtrack(matchsticks, len, 0, target);
    }
    
    bool backtrack(vector<int>& matchsticks, vector<int>& len, int idx, int target) {
                    // cout << len[0] << "/" << len[1] << "/" << len[2] << "/" << len[3] << endl;

        if (idx == matchsticks.size()) {
            return (len[0] == len[1]) && (len[2] == len[3]) && (len[0] == len[2]);
        }
        
        for (int i=0; i<4; i++) {
            if (len[i] + matchsticks[idx] > target) continue;
            len[i] += matchsticks[idx];
            if (backtrack(matchsticks, len, idx+1, target)) return true;
            len[i] -= matchsticks[idx];
        }
        return false;
    }
};