class Solution {
public:
    string reorderSpaces(string text) {

        vector<string> strs;
        string curStr;
        int space = 0;
        for (int i=0; i<text.size(); ++i) {
            if (text[i] == ' ') {
                if (curStr.size() > 0){
                    strs.push_back(curStr);
                    curStr.clear();
                } 
                ++space;
            }
            else curStr += text[i];
        }
        
        if (curStr.size() > 0){
            strs.push_back(curStr);
            curStr.clear();
        }
        
        if (strs.size() == 1) 
            return strs[0] + string(space, ' ');
        
        int dist = space / (strs.size()-1);
        int res = space % (strs.size()-1);
        
        string ans;
        for (int i=0; i<strs.size(); ++i) {
            string & str = strs[i];
            ans += (str + ((i == strs.size()-1) ? "" : string(dist, ' ')));
        }
        if (res) ans += string(res, ' ');
        
        return ans;
    }
};