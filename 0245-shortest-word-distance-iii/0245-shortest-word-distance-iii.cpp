class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> idxMap;
        int idx=0;
        for (auto & word : wordsDict) {
            idxMap[word].push_back(idx);
            ++idx;
        }
        
        /*
        practice : 0
        makes : 1, 4
        perfect : 2
        coding : 3
        
        */
        
        int ans = INT_MAX;
        for (auto & candIdx : idxMap[word1]) {
            auto it = upper_bound(idxMap[word2].begin(), idxMap[word2].end(), candIdx);
            if (it == idxMap[word2].end()) continue;
            
            ans = min(ans, (*it)-candIdx);
        }
        
        for (auto & candIdx : idxMap[word2]) {
            auto it = upper_bound(idxMap[word1].begin(), idxMap[word1].end(), candIdx);
            if (it == idxMap[word1].end()) continue;
            
            ans = min(ans, (*it)-candIdx);
        }
        
        return ans;
    }
};