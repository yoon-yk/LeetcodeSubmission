class Solution {
public:
    int minSwaps(string s) {
        vector<int> opens;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '[') {
                opens.push_back(i);
            } else {
                if (!opens.empty()) opens.pop_back();
            }
            
            /*
            "][][]]][[[[][]][[]]["   
            */
        }
    
        return (opens.size()+1) >> 1;
    }
};