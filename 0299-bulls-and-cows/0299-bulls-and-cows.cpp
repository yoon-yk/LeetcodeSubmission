class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, int> mp;
        for (int i=0; i<secret.size(); ++i) ++mp[secret[i]];
        
        int nB = 0, nC = 0;
        for (int i=0; i<guess.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++nB; --mp[guess[i]];
            }            
        }
        
        for (int i=0; i<guess.size(); ++i) {
            if (secret[i] != guess[i] && mp[guess[i]] > 0) {
                ++nC; --mp[guess[i]];
            }
        }
        
        return to_string(nB)+'A'+to_string(nC)+'B';
    }
};