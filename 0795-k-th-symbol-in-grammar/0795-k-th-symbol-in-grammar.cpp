class Solution {
public:
int kthGrammar(int n, int k) {
    if (n == 1) return 0;
    if (n == 2) return k % 2 == 0;

    if (k & 1) // odd
        return kthGrammar(n-1, (k+1)/2);
    return !kthGrammar(n-1, k/2);
}
};