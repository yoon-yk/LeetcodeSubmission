class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> m = {
            {1, 'I'},
            {5, 'V'}, 
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        
        vector<int> nums;
        int cnt = -1;
        while (num > 0) {
            nums.push_back(num%10);
            num /= 10;
            cnt++;
        }
        
        int curDigit, curTenth;
        string ans;
        for (int i=cnt; i>=0; i--, cnt--) {
            curDigit = nums[i];
            curTenth = pow(10, cnt);
            if (curDigit == 4) {
                ans += m[curTenth];
                ans += m[curTenth*5];
            } else if (curDigit == 9) {
                ans += m[curTenth]; 
                ans += m[curTenth*10];
            } else {
                if (curDigit >= 5) {
                    curDigit -= 5;
                    ans += m[curTenth*5];
                }
                for (int i=0; i<curDigit; i++)
                    ans += m[curTenth];
            } 
        }
        
        return ans;

    }
};