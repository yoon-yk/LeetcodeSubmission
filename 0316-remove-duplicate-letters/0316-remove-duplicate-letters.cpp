class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_seen(26, -1);

        int n = s.size();
        for (int i=0; i<n; ++i)
            last_seen[s[i]-'a'] = i;
        
        deque<char> st;
        vector<bool> seen(26, false);
        for (int i=0; i<n; ++i) {
            int ch = s[i] - 'a';
            if (seen[ch]) continue;

            // 처음 보는 char (stack에 없음)
            // stack 에 들어가있는 chars 들 중
            // 지금과 비교했을 때 alphabetical order이 뒷 순위고 &&
            // 뒤에서 또 나올 애들 
            while (!st.empty() && ch < st.back() &&
                last_seen[st.back()] > i) {
                    seen[st.back()] = false; // 못 본 것으로 처리
                    st.pop_back();
            }
            seen[ch] = true;
            st.push_back(ch);
        }
        string ans;
        while (!st.empty()) {
            ans += (char)st.front() + 'a'; st.pop_front();
        }
        return ans;
    }
};