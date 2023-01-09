class Solution {
public:
    bool isPerfectSquare(int num) {
        return ((floor(sqrt(num))) == (ceil(sqrt(num))));
    }
};