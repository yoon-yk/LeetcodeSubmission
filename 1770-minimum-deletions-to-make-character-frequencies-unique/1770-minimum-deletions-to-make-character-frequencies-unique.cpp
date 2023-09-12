class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (auto & c : s) {
            ++freq[c-'a'];
        }

        vector<int> sorted;
        for (int i=0; i<26; ++i) {
            if (!freq[i]) continue;
            sorted.emplace_back(freq[i]);
        }
        /*
        2 1 2
        */

        int cnt = 0;
        sort(sorted.begin(), sorted.end(), greater<int>());
        for (int i=0; i<sorted.size(); ++i) {
            if (i && sorted[i-1] <= sorted[i]) {
                int tmp = sorted[i-1] == 0 ? 0 : sorted[i-1]-1;
                cnt += sorted[i]-tmp;
                sorted[i] = tmp;
            }
        }

        return cnt;
    }
};