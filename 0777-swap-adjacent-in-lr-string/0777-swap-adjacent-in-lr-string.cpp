class Solution {
public:
    bool canTransform(string start, string end) {
        
        /*
        "XL" => "LX" // moving x forward
        "RX" => "XR" // moving x backward
        
        start = "RXXLRXRXL"
                "XRXLRXRXL"
                "XRLXRXRXL"
                "XRLXXRRXL"
                "XRLXXRRLX"
        end   = "XRLXXRRLX"
        
        "LXR"
        "LRX"
        "XLR"
        
        "RXL"
        

        // "L and R order shouldn't be changed"
        
        start = "XLLR"
        end   = "LLXR"
        
        start = "LLLXR" // can move x 3 times
                "LXLLR"
                "XLLLR"
                "LXRLL"
        end   = "LXLRL"
        
        
        1. # of L , # of R should be the same
        2. "L can't go more righter side"
        3. "R can't go more lefter side"
        4. LR should be in same order
        
        X
        0
        
        L
        
        "RLX"
        "XLR"
        
        "RLX"
        "RXL"
        "XRL"
        
        
        
        */
        
        vector<pair<int, int>> V; // <isL, val> = can't go further than this value
        for (int i=0; i<start.size(); i++) {
            if (start[i] == 'L')
                V.push_back(pair(true,i));
            else if (start[i] == 'R')
                V.push_back(pair(false,i));
        }
        
        for (int i=end.size()-1; i>=0; i--) {
            if (end[i] == 'X') continue;
            if (V.empty()) return false;
            
            if (end[i] == 'L') {
                if (!V.back().first 
                    || V.back().second < i) 
                    return false;
                V.pop_back();
            } else if (end[i] == 'R') {
                if (V.back().first 
                    || V.back().second > i) 
                    return false;
                V.pop_back();
            }
        }
        return V.empty();
    }
};