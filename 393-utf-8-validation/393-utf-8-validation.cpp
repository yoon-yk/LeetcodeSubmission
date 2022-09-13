class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int cur = 0;
        bool pass = true;
        
        while (cur < data.size()) {

            int count = 0;
            int std = cur;
            while ((data[cur] & 128) == 128 && count < 8) {
                count ++;
                data[cur] <<= 1;
            }
            
            cur++;
            
            if (count == 0) continue;
            else if (count == 1 || count > 4) return false;
            
            count--;
            
            for (; count > 0 && cur<data.size(); count--, cur++) {
                pass = false;
                if ((data[cur] & 128) == 128) {
                    data[cur] <<= 1;
                    if ((data[cur] & 128) == 0) {
                        pass = true;
                    }
                }
                if (!pass) return false;
            }

            if (count!= 0) return false;
            
        }        
        
        return pass;
    }
};