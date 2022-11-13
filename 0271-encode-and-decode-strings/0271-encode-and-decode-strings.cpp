class Codec {
public:
    int INFOSIZE = 5;
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        int sizeInfoLen, zeroCnt;
        string ret, sizeInfo;
        
        sizeInfo = to_string(strs.size());
        sizeInfoLen = (sizeInfo).size();
        zeroCnt = (int)(INFOSIZE-sizeInfoLen);
        ret += string(zeroCnt, '0');
        ret += sizeInfo;
        
        for (auto & str : strs) {
            sizeInfo = to_string(str.size());
            sizeInfoLen = (sizeInfo).size();
            zeroCnt = (int)(INFOSIZE-sizeInfoLen);
            ret += string(zeroCnt, '0');
            ret += sizeInfo;
            ret += str;
        }
        // cout << ret << endl;
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int cnt = stoi(s.substr(0, INFOSIZE));
        int startIdx = INFOSIZE, len;
        for (int i=0; i<cnt; i++) {
            len = stoi(s.substr(startIdx, INFOSIZE));
            startIdx += INFOSIZE;
            ans.push_back(s.substr(startIdx, len));
            startIdx += len;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));