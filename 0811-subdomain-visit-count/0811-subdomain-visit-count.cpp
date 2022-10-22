class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        vector<string> ans;
        unordered_map<string, int> mp;
        
        for (auto& domain : cpdomains) {
            int pos = domain.find(' ');
            int cnt = stoi(domain.substr(0, pos));
            string rest = domain.substr(pos+1);
            
            string curStr; 
            for (int i=rest.size(); i>=0; i--) {
                if (rest[i] == '.') 
                    mp[curStr] += cnt;
                curStr = rest[i] + curStr;
            }
            mp[curStr] += cnt;
        }
        
         
        for (auto & entry : mp) {
            string domain = entry.first;
            int domainCnt = entry.second;
                
            ans.push_back(to_string(domainCnt) + " " + domain);
        }

        return ans;
    }
};