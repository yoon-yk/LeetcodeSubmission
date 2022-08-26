class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string num = to_string(n);
        int size = num.length();
        
        unordered_map<string, int> hashM;
        for (int i=1; i<=pow(10, size); i<<=1) {
            if (pow(10, size-1)>i) continue;
            hashM[to_string(i)]++;
        }

        return backtrack(0, size, num, hashM);
        
    }
    
    bool backtrack(int idx, int size, string& curN, unordered_map<string, int>& hashM) {

        if (idx == size) {
            if (hashM.count(curN))
                return true;
            return false;
        }
        
        for (int i=idx; i<size; i++) {
            swap(curN[i], curN[idx]);
            if (backtrack(idx+1, size, curN, hashM))
                return true;
            swap(curN[i], curN[idx]);
        }
        
        return false;
    }
};