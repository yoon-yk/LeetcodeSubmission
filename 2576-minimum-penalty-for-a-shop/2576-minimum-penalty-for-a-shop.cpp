class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();
        vector<int> missingCustomersAfter(n+1),
                    penaltyFromNoCustomer(n+1);

        for (int i=n-1; i>=0; --i) {
            missingCustomersAfter[i] = 
                missingCustomersAfter[i+1] + (c[i] == 'Y');
        }

        for (int i=1; i<=n; ++i) {
            penaltyFromNoCustomer[i] = 
                penaltyFromNoCustomer[i-1] + (c[i-1] == 'N');
        }

        int idxWminPen = 0;
        vector<int> pen(n+1);
        for (int i=0; i<=n; ++i) {
            pen[i] = missingCustomersAfter[i] + 
                    penaltyFromNoCustomer[i];
            
            if (pen[i] < pen[idxWminPen]) {
                idxWminPen = i;
            }
        }

        return idxWminPen;
    }
};