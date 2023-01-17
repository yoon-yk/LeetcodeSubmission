class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> dq;
        for (auto & c : s) {
            if (!dq.empty() && dq.back().first == c) {
                ++dq.back().second;
                if (dq.back().second == k) dq.pop_back();
            } else {
                dq.push_back({c, 1});
            }
        }
        string ans;
        while (!dq.empty()) {
            ans += string(dq.front().second,dq.front().first);
            dq.pop_front();
        }
        return ans;
    }
};