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

        if (idx == size) {
            if (hashM.count(curN))
                return true;
            return false;
        }

        
        bool ans = false;
        for (int i=idx; i<size; i++) {
            if (ans) break;
            swap(curN[i], curN[idx]);
            ans = ans || (backtrack(idx+1, size, curN, hashM));
            swap(curN[i], curN[idx]);
        }
        
        return ans;
    }
};