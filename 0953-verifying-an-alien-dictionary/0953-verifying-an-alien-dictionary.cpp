class Solution {
public:
    vector<int> orders;
    bool areSorted(vector<string>& words, int idx) {
        string & first = words[idx];
        string & second = words[idx+1];
        
        int p1 = 0, p2 = 0;
        while (p1 < first.size() && p2 < second.size()) {
            if (first[p1] == second[p2]) ++p1, ++p2;
            else break;
        }
        if (p1 == first.size()) return true;
        else if (p2 == second.size()) return false;
        
        return (orders[first[p1]-'a'] < orders[second[p2]-'a']);
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        orders.resize(26);
        int idx=0;
        for (auto & c : order) {
            orders[c-'a'] = idx++;
        }
        
        for (int i=0; i<words.size()-1; ++i) {
            if (!areSorted(words, i)) return false;
        }
        
        return true;
    }
};