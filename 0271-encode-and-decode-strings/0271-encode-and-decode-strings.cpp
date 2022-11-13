class Codec {
public:
    int INFOSIZE = 5;
    
    string& getZeroSize(int size, string& res) {
        
        string sizeInfo = to_string(size);
        int sizeInfoLen = sizeInfo.size();
        int zeroCnt = (int)(INFOSIZE-sizeInfoLen);
        
        res = (string(zeroCnt, '0') + sizeInfo);
        return res;
    }
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string ret;
        
        string res;
        ret += getZeroSize(strs.size(), res);
        
        for (auto & str : strs) {
            ret += getZeroSize(str.size(), res) + str;
        }
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