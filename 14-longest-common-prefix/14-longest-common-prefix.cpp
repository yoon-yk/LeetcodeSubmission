class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(), strs.end(), [](string& a, string& b)
             {return a.length() < b.length();});
        
        string stdstr = strs[0];
        int len = stdstr.size();
        int arrSize = strs.size();
        int start = 0, end = 0;
        
        for(int i=0; i<len; i++){
            
            for(int j=1; j<arrSize; j++) {
                if (stdstr[i]!=strs[j][i]) {
                    return stdstr.substr(start, i);
                }
            }
            end++;
        }
        
        return stdstr;
    }
};