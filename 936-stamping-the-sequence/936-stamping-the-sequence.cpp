class Solution {
public:
    int can_replace(string &s, string &t , int pos){
        for (int i=0; i<s.size(); i++)
            if (t[i+pos]!='?' && t[i+pos]!=s[i]) // ?가 아닌데도 같지 않다면 
                return 0;    
        return 1;
    }
    
    int replace(string &s, string &t , int pos){
        int replace=0;
        for (int i=0;i<s.size();i++)
            if (t[i+pos]!='?')
                t[i+pos]='?', replace++;
        return replace;
    }
    
    vector<int> movesToStamp(string s, string t) {
        vector<int> res;
        vector<bool> vis(t.size(), false);
        int cnt=0;
        
        while (cnt!=t.size()){
            bool changed = false;
            for (int i=0; i<=t.size()-s.size(); i++)
                if (!vis[i] && can_replace(s,t,i)){
                    cnt += replace(s,t,i);
                    vis[i]=true;
                    changed=true;
                    res.push_back(i);
                }
            
            if (!changed)
                return {};
        }
        reverse(res.begin(),res.end());
        return res;
    }
};