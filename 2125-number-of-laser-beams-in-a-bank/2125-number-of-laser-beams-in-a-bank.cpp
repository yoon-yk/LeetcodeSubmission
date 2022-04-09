class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ret = 0;
        int rowN = bank.size();
        if (rowN == 1) return 0;
        
        int beamsN[rowN];
        
        for (int i=0; i<rowN; i++) {
            int cnt = 0;
            for (int j=0; j<bank[0].size(); j++) {
                if (bank[i][j] == '1') cnt++;
            }
            beamsN[i] = cnt;
        }
        
        for (auto i:beamsN) cout<<i<<endl;
        int i=0, j=1;
        while (i < j && j < rowN) {
            while (j < rowN && beamsN[i] == 0) {i++; j++;}
            while (j < rowN && beamsN[j] == 0) j++;
            if (i >= rowN || j >= rowN) break;
            cout << "i : " << i << " / j : " << j << endl;
            ret += beamsN[i] * beamsN[j];
            i=j; j++;
        }
        
        return ret;
    }
};