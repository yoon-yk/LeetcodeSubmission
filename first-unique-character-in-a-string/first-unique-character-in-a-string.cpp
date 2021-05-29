class Solution {
public:
    map<char, int> hashT;
        
    void createHT(string s){
        int i=0;
        for(auto &c : s)
            hashT[c]++;
    }
    
    int firstUniqChar(string s) {
        int i, flag = 0;
        createHT(s);
        
        for(i=0; i<s.size(); i++){
            if(hashT[s[i]]==1){
                flag = 1;
                break;
            }
        }

        return flag? i : -1;
    }
};