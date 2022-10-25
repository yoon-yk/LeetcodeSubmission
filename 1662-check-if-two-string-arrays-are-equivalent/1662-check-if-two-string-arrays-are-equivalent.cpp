class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       queue<char> Q;
        for (auto & word : word1) {
            for (auto & ch : word) {
                Q.push(ch);
            }
        }
        
        
        int cnt = 0;
        for (auto & word : word2) {
            for (auto & ch : word) {
                if (Q.empty() || ch != Q.front()) return false;
                Q.pop();
            }
        }
        
        return Q.empty();
   }
};