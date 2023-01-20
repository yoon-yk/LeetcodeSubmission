class Solution {
public:
    int cnt;
    unordered_map<string, int> mp;
    vector<string> v;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        cnt = 0;
        stringstream s(longUrl);
        string ret;
        while (!s.eof()) {
            string str;
            getline(s, str, '/');
            if (!mp.count(str)) {
                mp[str] = cnt++; v.push_back(str);
            }
            ret += to_string(mp[str]);
            if (!s.eof()) ret += '/';
        }        
        return ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        stringstream s(shortUrl);
        string ret;
        while (!s.eof()) {
            string str;
            getline(s, str, '/');
            ret += v[stoi(str)];
            if (!s.eof()) ret += '/';
        }        
        return ret;

    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));