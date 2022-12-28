class Solution {
public:
    int left = 0, right = 1;
    bool canChange(string start, string target) {
        // l can go only lefter side, r can go only righter side
        int p1 = 0, p2 = 0;
        int n = start.size();
        int lastCh = -1;
        int lastChIdx = -1;
        while (true) {
            while (p1 < n && start[p1] == '_') ++p1;
            while (p2 < n && target[p2] == '_') ++p2;
            if (p1 == n || p2 == n) break;
            if (start[p1] != target[p2]) return false;
            if (start[p1] == 'L' && p1 < p2 || 
                start[p1] == 'R' && p2 < p1) return false;
            ++p1, ++p2;
        }
        return (p1 == n && p2 == n);
    }
};