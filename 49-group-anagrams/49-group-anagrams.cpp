class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> hashT;
        int size = strs.size();
        for (string &curStr:strs) {
            string copy = curStr;
            sort(curStr.begin(), curStr.end());
            hashT[curStr].push_back(copy); // not insert!! push_back for map!!!
        }
        
        vector<vector<string>> answer;
        for (auto elm : hashT) // ********************** pair!!!!!!!!!!!!
            answer.push_back(elm.second); // *********** second!!!!!!!!!!
        
        return answer;
    }
};