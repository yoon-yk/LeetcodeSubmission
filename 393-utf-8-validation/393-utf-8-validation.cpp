class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int cur = 0;
        
        while (cur < data.size()) {

            int count = 0;
            while ((data[cur] & 128) == 128 && count < 8) {
                count ++;
                data[cur] <<= 1;
                if (count > 4) return false;
            }
            
            cur++;
        
            if (count == 1) return false;
            else if (!count) continue;
            
            count--;
            
            for (; count > 0 && cur<data.size(); count--, cur++) {
                if (!(((data[cur] & 128) == 128) && (data[cur]<< 1 & 128) == 0))
                    return false;
            }

            if (count) return false;
        }        
        
        return true;
    }
};