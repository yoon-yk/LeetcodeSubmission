class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        // Parse string 
        // 9001 discuss leetcode com
        // [com]  += 9001
        // [leetcode.com] += 9001 
        // [discuss.leetcode.com] += 9001
        
        // "900 google.mail.com", 
        // "50 yahoo.com", 
        // "1 intel.mail.com", 
        // "5 wiki.org"
        /*
        [com] += 900 + 50 + 1
        [mail.com] += 900 + 1
        [google.mail.com] += 900
        [yahoo.com] += 50
        [intel.mail.com] += 1
        
        
        1. parse the string 
            --> extract number
            --> extract each part (pt1, pt2, (pt3-optional))
        2. Add to hash Map
            --> starting from the last part (pt3 or pt2)
            --> look up if it exists in a hash map 
            -->     if not, make the new one
            --> and add the number of visit
            --> add the next part and repeat 
                until it reaches the first part 
                
        3. Iterate the hash Map and 
            concanate its value and key to make a string output as it is instructed 
            
        */
        
        int idx;
        vector<string> stringVec(3);
        unordered_map<string, int> hashM;
        for (auto &str : cpdomains) {
            idx=0;
            stringVec.clear();
            int frequency = extractNumber(str, idx);
            int stringCnt = extractDomain(str, idx, stringVec);            
            string curDomain;
            for (int i=stringCnt-1; i>=0; i--) {
                if (curDomain.size() == 0) 
                    curDomain = stringVec[i];
                else 
                    curDomain = stringVec[i] + '.' + curDomain;
                hashM[curDomain] += frequency;
            }
        }
        
        vector<string> ans;
        for (auto &pair : hashM) 
            ans.emplace_back((to_string(pair.second) + " " + pair.first));
        return ans;
        
    }
    
    int extractNumber(string& str, int &idx){
        string curStr = "";
        while (str[idx] != ' ') {
            curStr += str[idx];
            idx++;
        }
        return stoi(curStr);
    }
    
    int extractDomain(string& str, int &idx, vector<string> &stringVec) {
        string curStr = "";
        int curStrN = 0;
        idx++;
        while (idx<str.size()) {
            if (str[idx] == '.'){
                stringVec[curStrN++] = curStr;
                curStr = "";
            }
            else curStr += str[idx];
            idx++;
        }
        stringVec[curStrN++] = curStr;
        return curStrN;
    }
};