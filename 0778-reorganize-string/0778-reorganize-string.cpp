class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26);
        for (auto & c : s) {
            ++count[c-'a'];
        }
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<26; ++i) {
            if (count[i] == 0) continue;
            pq.push({count[i], i});
        }

        if (pq.top().first > ((s.size()+1)/2)) return "";

        queue<pair<int, int>> Q;
        while (!pq.empty()) {
            auto [cnt, ch] = pq.top(); pq.pop();
            Q.push({ch, cnt});
        }

        string str(s.size(), '*');
        int idx = 0;
        while (!Q.empty()) {
          auto [ch, cnt] = Q.front(); Q.pop();
        //   cout << (char)(ch + 'a') << ':' << cnt << endl;

          while (cnt--) {
            str[idx] = ch + 'a';
            idx = (idx + 2);
            if (idx >= str.size()) idx = 1;
          }
        //   cout << str << endl;
        }

        return str;
    }
};