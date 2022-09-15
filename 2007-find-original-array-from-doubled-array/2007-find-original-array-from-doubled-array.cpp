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
        
        if (changed.size() % 2) return {};
        
        // put every number into hash M to mark if it is used before
        unordered_map<int, int> hashM;
        vector<int> ans;
        
        /*  (changed) [1, 2, 2, 4, 4, 8] */
        
        int evenCnt = 0, oddCnt = 0;
        for (int &n : changed) {
            hashM[n]++;
            if (n%2 == 0) evenCnt++;
            else oddCnt++;
        }
        if (oddCnt > evenCnt) return {};   // if the number of odds < number of even : [1, 2, 2, 4]

        // sort the changed array to access the number by increasing order
        sort(changed.begin(), changed.end());
            
        int origN, doubledN, n = changed.size();

        // (changed) [1, 1, 2, 2, 4, <4>, 8, 8]
        // origN = 4, doubleN = 8
        // (hashM) 1 : 0, 2 : 0, 4 : 0, 8 : 0
        // (ans) 1, 1, 4, 4

        int totalCnt = hashM.size();
        
        for (int i=0; i<n; i++) {
            // check the current number is still valid 
            if (hashM[changed[i]] < 1) continue;
            
            // if doubled number is in the hash Map and it is unmarked, 
            origN = changed[i], doubledN = origN << 1;
            if (!hashM.count(doubledN)) return {};
            
            if (origN == 0) { // (corner case : 0)
                if (hashM[origN] > 1) {
                    hashM[origN] -= 2;
                    if (hashM[origN] == 0) 
                        totalCnt--;
                    
                    ans.push_back(origN);
                }
            }
            else if (hashM.count(doubledN) && hashM[doubledN] > 0) {  
                // then it's the doubled integer 
                
                // erase both number(orig + doubled)
                if (--hashM[origN] == 0)
                    totalCnt--;
                
                if (--hashM[doubledN] == 0)
                    totalCnt--;

                // put the original number into the answer 
                ans.push_back(origN);
            }
        }
        
        // if any left over ?? 
        if (totalCnt != 0) return {};
        
        return ans;
    }
};