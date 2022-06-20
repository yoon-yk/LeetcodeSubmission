class Solution {
public:
    
    int getNext(int n) {
        int sum = 0, digit;
        while (n > 0) {
            digit = (n % 10);
            sum += digit*digit;
            n = n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);
        
        while(fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        
        return fastRunner == 1;
            
    }
};