class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> end(26, -1);
        
        for (int i=0; i<s.length(); i++)
            end[s[i]-'a'] = i;

        vector<int> ans;
        int startIdx = 0, endIdx = 0;
        for (int i=0; i<s.length(); i++) {
            endIdx = max(endIdx, end[s[i]-'a']);
            if (i == endIdx){
                ans.push_back(endIdx-startIdx+1);
                startIdx = i+1;
            }
        }
        
        return ans;
        
        
    }
};