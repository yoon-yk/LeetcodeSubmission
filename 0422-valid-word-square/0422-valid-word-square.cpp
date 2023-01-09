class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<words[i].size(); ++j) {
                if (words.size()-1 < j || words[j].size()-1 < i
                 || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};