class Solution {
public:
    int getSum(int x, int y) {
    
        int a = abs(x), b = abs(y);
        if (a < b) return getSum(y, x);
        
        bool sign = (x < 0);
        int answer = 0;
        
        if (x * y >= 0) {    
            int carry;
            while (b !=0) {
                answer = a ^ b;
                carry = (a&b) << 1;
                a = answer, b = carry;
            }            
        } else {
            
            int borrow;
            while (b != 0) {
                answer = a ^ b;
                borrow = ((~a) & b) << 1;
                a = answer, b = borrow;
            }
        }
        
        return (sign) ? -1 * a : a;   
    }
};