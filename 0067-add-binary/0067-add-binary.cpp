class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        bool carry = false;
        int ret, pt1 = a.size()-1, pt2 = b.size()-1, bA, bB;
        while (pt1 >= 0 || pt2 >= 0 || carry) {
            bA = (pt1 >= 0) ? a[pt1] - '0' : 0;
            bB = (pt2 >= 0) ? b[pt2] - '0' : 0;
            ret = bA + bB + carry;
            
            carry = (ret >= 2);
            ret = (ret & 1);
            
            ans += ret + '0';
            --pt1, --pt2;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};