class Solution {
public:
    bool isPerfectSquare(int num) {
        long long cnt = 1, sum = cnt;
        while(cnt<=num) {
            if (sum == num) return true;
            cnt +=2;
            sum += cnt;
        }
        return false;
    }
};