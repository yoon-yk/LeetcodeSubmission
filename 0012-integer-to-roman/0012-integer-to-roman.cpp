class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> mp = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        
        int len = 0;
        int n = num;
        while (n > 0) {
            n /= 10;
            len ++;
        }
        
        string ans;
        
        n = num;
        while (n > 0) {
            int tenth = pow(10, len-1);
            int digit = n / tenth;
            
            if (digit == 9) {
                ans += mp[tenth];
                ans += mp[tenth*10];
            } else if (digit == 4) {
                ans += mp[tenth];
                ans += mp[tenth * 5];
            } else {
                if (digit >= 5) {
                    ans += mp[5 * tenth];
                    digit -= 5;
                }
                for (int i=0; i < digit; i++) {
                    ans += mp[tenth];
                }
            }
            
            n = n % tenth;
            len--;
        }
        
        return ans;
    }
};