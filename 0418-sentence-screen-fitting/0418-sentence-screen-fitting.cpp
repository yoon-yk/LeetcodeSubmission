class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int c = cols, i=0, n = sentence.size(), pre;
        vector<int> arr(n, -1);
        for (int r=0; r<rows; ++r){
            if (arr[i%n] != -1) i += arr[i%n];
            else {
                pre = i;
                while ((c -= sentence[i%n].size()) >= 0) ++i, --c;
                c = cols;
                arr[pre%n] = i-pre;
            }
        }
        return i/n;
    }
};