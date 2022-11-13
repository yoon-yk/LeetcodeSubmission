class Codec {
public:
    string Int2String(int x) {
        string result;
        for(int i = 0; i < 4; i++) {
            unsigned char c = (x >> (i * 8)) & 0xFF;
            // DO TAKE CARE that we need to use static_cast convert it to unsigned!!
            result.push_back(static_cast<char>(c));
        }
        return result;
    }

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(string& s : strs) {
            encoded += Int2String(s.size());
            encoded += s;
        }
        return encoded;
    }
    
    int String2Int(string s) {
        int result = 0;
        for(int i = 0; i < 4; i++) {
            // DO TAKE CARE that we need to use static_cast convert it to unsigned!!
            result += static_cast<unsigned char>(s[i] << (i * 8));
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.size()) {
            int len = String2Int(s.substr(i, 4));
            i += 4;
            decoded.push_back(s.substr(i, len));
            i += len;
        }
        return decoded;
    }
};