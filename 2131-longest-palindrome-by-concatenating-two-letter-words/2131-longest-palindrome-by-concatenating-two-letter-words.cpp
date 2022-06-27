class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int> M;
        unordered_map<string, int> pM;
        
            
        // 1. 모두 집어넣기
        for (auto w : words) {
            if (w[0]==w[1]){
                if (pM.find(w)!=pM.end())
                    pM[w]++;
                else pM[w] = 1;
            }
            else {
                if (M.find(w)!=M.end())
                    M[w]++;
                else M[w] = 1;
            }
        }
        
        // 2. 짝 찾기
        int maxLen = 0, curLen = 0, 
        commMax = 0, maxEven = 0;
        bool center = false;
        
        for (auto w: pM) {
            if (!center && w.second%2==1) {
                center = true;
                maxLen += w.second * 2;
            } else {
                curLen = w.second;
                curLen = (curLen%2==0) ? curLen : curLen-1;
                maxLen += curLen*2;
            }
        }
        
        for (auto w : M) {
            string target = w.first;
            swap(target[0], target[1]);
            
            if (M.find(target) != M.end() 
                     && M[target] > 0) {
                
                commMax = min(M[target], w.second);
                maxLen += commMax*4;
                M[w.first] = M[target] = 0;
            }
        }
        
        return maxLen;
    }
};