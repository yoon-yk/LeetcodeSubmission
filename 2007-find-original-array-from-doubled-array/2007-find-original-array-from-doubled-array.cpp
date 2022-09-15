class Solution {
public:
    
    /*
    [1, 3, 4, 2, 6, 8]
    [1, 3, 4] 
    
    [1, 2, 4, 8]
    [1, 4]
    
    [1, 2, 6, 7, 8, 3, 14, 4]
    [1, 2, 3, 4, 6, 7, 8, 14]
    
    [1, 1, 2, 2, 3, 3, 4, 4, 7, 7, 8, 8, 14, 14]
    
    [-, -, -, -, -, -, -, -]
    
    [-, -, -, -, -, -, -, -]
    
    [0, 0, 0, 1]
    
    
    // what if it's not a doubled array??? (corner case!)
    // if the array size is odd 
    // 
    
    appended elems : orig elem * 2 
    
    */
    vector<int> findOriginalArray(vector<int>& changed) {
        
        // if (changed.size() % 2) return {};
        
        unordered_map<int, int> hashM;
        vector<int> ans;
                
        int evenCnt = 0, oddCnt = 0;
        for (int &n : changed) {
            hashM[n]++;
            if (n%2 == 0) evenCnt++;
            else oddCnt++;
        }
        // if (oddCnt > evenCnt) return {};   // if the number of odds < number of even : [1, 2, 2, 4]

        sort(changed.begin(), changed.end());
            
        int origN, doubledN, n = changed.size();
        int totalCnt = hashM.size();
        
        for (int i=0; i<n; i++) {
            origN = changed[i], doubledN = origN << 1;

            if (hashM[origN] < 1) continue;
            
            if (--hashM[origN] == 0)     
                --totalCnt;
            
            if (!hashM.count(doubledN) || hashM[doubledN] < 1) return {};

            if (--hashM[doubledN] == 0)
                --totalCnt;

            ans.push_back(origN);
        }
        
        if (totalCnt != 0) return {};
        
        return ans;
    }
};