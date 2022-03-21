class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0) return 0;
        if (s.length()==1) return 1;
        int left = 0, right = 0, count, maxCount = INT_MIN;
        
        unordered_map <char, int> hashT;
        while ((left <= right) && (right < s.length())) {
            count = 1; 
            hashT[s[left]] = 1; // 첫번째 글자 해쉬테이블에 넣기
            while ((right+1 < s.length()) 
                   && (s[right]!=s[right+1]) 
                   && (hashT.find(s[right+1])==hashT.end())) {
                hashT[s[right+1]] += 1;
                right++; count++; 
            }
            hashT.clear();
            left ++;
            right = left;
            maxCount = max(count, maxCount);
        }
     return maxCount;
    }
};