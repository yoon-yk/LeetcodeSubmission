class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> A, B;
        for(auto a:s) A[a]+=1;
        for(auto b:t) B[b]+=1;
        if(A.size()!=B.size()) return false;
        for(const auto a:A) if(a.second != B[a.first]) return false; 
        return true;
    }
};