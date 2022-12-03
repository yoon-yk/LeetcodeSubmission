class Solution {
public:
    bool canTransform(string start, string end) {
        int sIdx = 0, eIdx = 0;
        while (sIdx < start.size() || eIdx < end.size()) {
                        
            while (sIdx < start.size() && start[sIdx] == 'X')
                ++sIdx;
            while (eIdx < end.size() && end[eIdx] == 'X')
                ++eIdx;
            
            if (sIdx == start.size() && eIdx == end.size())
                return true;
            else if (sIdx == start.size() || eIdx == end.size())
                return false;
            
            if ((start[sIdx] != end[eIdx]) ||
                (start[sIdx] == 'L' && sIdx < eIdx) ||
                (end[eIdx] == 'R' && sIdx > eIdx)) return false;
            
            ++sIdx, ++eIdx;
        }

        
        return (sIdx == start.size()) && (eIdx == end.size());
    }
};