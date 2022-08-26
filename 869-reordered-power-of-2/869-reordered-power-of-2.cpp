class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        unordered_map<string, int> hashM;
        string num = to_string(n);
        int size = num.length();
        
        for (int i=1; i<=pow(10, size); i<<=1) 
            hashM[to_string(i)]++;
        

        return backtrack(0, size, num, hashM);
        
    }
    
    bool backtrack(int idx, int size, string& curN, unordered_map<string, int>& hashM) {
        
        // cout << curN << endl;
        
        if (hashM.count(curN))
            return true;
        
        if (idx == size)
            return false;
        
        bool ans = false;
        for (int i=idx; i<size; i++) {
            swap(curN[i], curN[idx]);
            ans = ans || (backtrack(idx+1, size, curN, hashM));
                // return true;
            swap(curN[i], curN[idx]);
        }
        
        return ans;
    }
};