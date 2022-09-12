class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        deque<int> dq;
        for (int & tk : tokens)
            dq.push_back(tk);
        
        int score = 0;
        int curPwr = power;
        bool isChanged = true;
        
        while (!dq.empty()) {
            
            if (!isChanged) // if unable to proceed
                break; 
            
            isChanged = false;
            if (curPwr >= dq.front()) {
                curPwr -= dq.front();
                dq.pop_front();
                score ++;
                isChanged = true;
            }
            
            else {
                if (score >= 1 && dq.size() > 1) {
                    score--;
                    curPwr += dq.back();
                    dq.pop_back();
                    isChanged = true;
                }
                
            }
        }
        return score;
    }
};