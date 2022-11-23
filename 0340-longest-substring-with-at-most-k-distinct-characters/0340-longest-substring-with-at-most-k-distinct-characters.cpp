class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        /*
        sliding window
        dict;
        while (end < ){
          if (dict[end] == 0) cnt++;
          dict[end]++;
          
          while (cnt > k) {
           left++;
           if (dict[left] == 1) cnt--;
           dict[left]--;
          }
          
          ans = max(ans, end-start+1);
        }
        
        return ans
        */ 
        int ans = 0, cnt = 0, left = 0;
        vector<int> dict(256, 0);
        for (int end=0; end<s.size(); end++) {
            if (dict[s[end]-' '] == 0) cnt++;
            dict[s[end]-' ']++;
            
            while (cnt > k){
                if (dict[s[left]-' '] == 1) cnt--;
                dict[s[left]-' ']--;
                left++;
            }
            
            ans = max(ans, end-left+1);
        }
        return ans;
    }
};