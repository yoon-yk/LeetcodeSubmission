class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        int lo = 0, hi = tokens.size()-1;
        int score = 0, curPwr = power;
        int maxScore = 0;
        
        while (lo <= hi) {

            if (curPwr >= tokens[lo]) {
                curPwr -= tokens[lo];
                lo++;
                score ++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0) {
                score--;
                curPwr += tokens[hi];
                hi--;
            } else break;
            
        }
        return maxScore;
    }
};