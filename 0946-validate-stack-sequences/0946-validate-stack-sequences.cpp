class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // [1, 2, 3 / 4 / 5]
        // [1, 2 / 3, 4 / 5]
        
        // [1, 2 / 3, 4, 5, 6 / 7, 8]
        
        // 한번 빠진 애의 왼쪽은 순서가 지켜져야 함 - freeze
        int n = pushed.size();
        unordered_map<int, int> idxMap;
        for (int i=0; i<n; ++i) {
            idxMap[pushed[i]] = i;
        }
        
        int curIdx = n+1;
        
        vector<bool> used(n, false);
        int freezeBound = -1;
        for (int i=0; i<n; ++i) {
            
            int curNum = popped[i];
            int curNumIdx = idxMap[curNum];
            for (int j=curNumIdx+1; j<freezeBound; ++j) {
                if (used[j] == false) {
                    return false;
                }
            }
            
            used[idxMap[popped[i]]] = true;
            freezeBound = max(curNumIdx, freezeBound);
        
        }
        return true;
    }
    
};