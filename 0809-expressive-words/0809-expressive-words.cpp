class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<vector<const char*>> wList(26);
        
        for (auto & word : words) 
            wList[word[0]-'a'].push_back(word.c_str());
        
        int cnt1, cnt2, ans = 0;
        for (int i=0, j1; i<s.size(); ++i) {
            j1 = i;
            while (j1 < s.size() && s[i] == s[j1]) ++j1;
            cnt1 = j1-i;
            
            for (auto & w : wList[s[i]-'a']) {
                cnt2 = 0;
                while ((*w) != '\0' && (*w) == s[i]) ++cnt2, ++w;
                
                if ((cnt1 >= 3 && cnt1 >= cnt2) || cnt1 == cnt2){
                    if ((*w)!='\0') wList[(*w)-'a'].push_back(w);
                    else if (j1 == s.size()) ++ans;
                }
            }
            wList[s[i]-'a'].clear();
            i = j1-1;
        }
        
        return ans;
    }
};