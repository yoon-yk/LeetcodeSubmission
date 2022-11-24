class Solution {
public:
    int shortestWay(string &source, string& target) {
        /*
          x z y x z
          1 1 2 2 3
        */
        
        unordered_map<char, int> cntDict;
        unordered_map<char, vector<int>> idxDict;
        for (int i=0; i<source.size(); i++) {
            idxDict[source[i]].push_back(i);
            cntDict[source[i]]++;
        }
        
        int start = 0, curIdx = -1;
        int windowsCount = 1;
        
        for (int end=0; end<target.size(); end++) {
            char curCh = target[end];

            if (!idxDict.count(curCh))
                return -1;
            
            auto findIdx = upper_bound(idxDict[curCh].begin(), idxDict[curCh].end(), curIdx);

            if (cntDict[curCh] == 0 
                || findIdx == idxDict[curCh].end()) {
                windowsCount++;
                while (start < end) {
                    cntDict[target[start]]++;
                    start++;
                }
                curIdx = idxDict[curCh][0]; 
            } else {
                curIdx = idxDict[curCh][findIdx - idxDict[curCh].begin()]; 
            }
            
            cntDict[target[end]]--;
        }
        
        return windowsCount;
    }
};