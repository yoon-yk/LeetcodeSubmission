class Solution {
public:
    void getString(deque<int>& nums, deque<string>& msgs, string& newStr) {
        string cur;
        while (!msgs.empty() && msgs.back() != "[") {
            cur = msgs.back() + cur;
            msgs.pop_back();
        }
        msgs.pop_back(); // pop '['
        int cnt = nums.back(); nums.pop_back();
        for (int i=0; i<cnt; ++i) 
            newStr += cur;
    }
    string& decodeString(string& s) {
        string ans;
        deque<int> nums;
        deque<string> msgs;
        string num;
        int cnt;
        for (char & c : s) {
            if (isdigit(c)) {
                num += c;
            } else if (c == ']') {
                string newStr;
                getString(nums, msgs, newStr);
                msgs.push_back(newStr);
            } else {
                if (c == '[') {
                    nums.push_back(stoi(num));
                    num.clear();
                }
                msgs.push_back(string(1, c));
            }
        }
        
        s.clear();
        while (!msgs.empty()) {
            s += msgs.front();
            msgs.pop_front();
        }
        return s;
    }
};