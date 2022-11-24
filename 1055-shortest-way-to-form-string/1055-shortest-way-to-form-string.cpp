class Solution {
public:
    int shortestWay(string &source, string& target) {
        /*
          x z y x z
          1 1 2 2 3
        */
        
        vector<vector<int>> idxDict(26);
        for (int i=0; i<source.size(); i++) {
            idxDict[source[i]-'a'].push_back(i);
        }
        
        int curIdx = -1;
        int windowsCount = 1;
        
        for (int end=0; end<target.size(); end++) {
            int curCh = target[end] - 'a';

            if (!idxDict[curCh].size())
                return -1;
            
            auto findIdx = upper_bound(idxDict[curCh].begin(), idxDict[curCh].end(), curIdx);

            if (findIdx == idxDict[curCh].end()){
                windowsCount++;
                curIdx = idxDict[curCh][0]; 
            } else
                curIdx = idxDict[curCh][findIdx - idxDict[curCh].begin()]; 
            
            
        }
        
        return windowsCount;
    }
};