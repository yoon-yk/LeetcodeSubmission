class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();
        vector<int> missingCustomersAfter(n+1),
                    penaltyFromNoCustomer(n+1);

        int sum = 0;
        for (int i=n-1; i>=0; --i) {
            missingCustomersAfter[i+1] = sum;
            sum += (c[i] == 'Y');
        }
        missingCustomersAfter[0] = sum;

        sum = 0;
        for (int i=1; i<=n; ++i) {
            sum += (c[i-1] == 'N');
            penaltyFromNoCustomer[i] = sum;
        }

        // for (auto & i : missingCustomersAfter) {
        //     cout << i << ' ';
        // }cout << endl;

        // for (auto & i : penaltyFromNoCustomer) {
        //     cout << i << ' ';
        // }cout << endl;

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