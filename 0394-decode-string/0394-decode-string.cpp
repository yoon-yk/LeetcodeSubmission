class Solution {
public:
    string decodeString(string s) {
        string ans;
        deque<int> nums;
        deque<string> msgs;
        msgs.push_back("");
        string num, msg;
        int cnt;
        for (char & c : s) {
            if (isdigit(c)) {
                if (!msg.empty()) {
                    msgs.push_back(msg);
                    msg.clear();
                }
                num += c;
            } else if (c == ']') {
                string cur;
                while (!msgs.empty() && msgs.back() != "[") {
                    cur = msgs.back() + cur;
                    msgs.pop_back();
                }
                msgs.pop_back(); // [
                int cnt = nums.back(); nums.pop_back();
                string newStr;
                for (int i=0; i<cnt; ++i) 
                    newStr += cur;
                msgs.push_back(newStr);
            } else {
                if (c == '[') {
                    nums.push_back(stoi(num));
                    num.clear();
                }
                msgs.push_back(string(1, c));
            }
        }
        
        string ret;
        while (!msgs.empty()) {
            ret += msgs.front();
            msgs.pop_front();
        }
        return ret;
    }
};