class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_seen(26, -1);

        int n = s.size();
        for (int i=0; i<n; ++i)
            last_seen[s[i]-'a'] = i;
        
        string ans;
        vector<bool> seen(26, false);
        for (int i=0; i<n; ++i) {
            int ch = s[i] - 'a';
            if (seen[ch]) continue;

            // 처음 보는 char (stack에 없음)
            // stack 에 들어가있는 chars 들 중
            // 지금과 비교했을 때 alphabetical order이 뒷 순위고 &&
            // 뒤에서 또 나올 애들 
            while (!ans.empty() && ch < ans.back()-'a' &&
                last_seen[ans.back()-'a'] > i) {
                    seen[ans.back()-'a'] = false; // 못 본 것으로 처리
                    ans.pop_back();
            }
            seen[ch] = true;
            ans.push_back(ch+'a');
        }
        return ans;
    }
};