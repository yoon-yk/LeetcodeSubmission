class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        // only even integer
        // maximum split --> we want to start with the smallest integer (2)
        // (2 ~ finalSum)
        
        // (1) : brute fore try everything - O(2^(finalSum-2))
        // (2) : memorize
        /*
        12
                [2, 4, 6, 8, 10, 12, 14]
        path    [2] (2) 
                [4 (2,2)] (2,2)
                [2,4(2,2)] (2,2,2)
                [2,6(2,2,2)] (2,2,2,2)
                [2,8(2,2,2,2)] (2,2,2,2,2)
                [2,10(2,2,2,2,2)] (2,2,2,2,2,2)
                [2, 12(2,2,2,2,2,2)] (2,2,2,2,2,2,2)
        */
        if (finalSum % 2) return {};

        vector<long long> ans;
        
        long long nextNum = 2, curSum = 0;
        while ((curSum + nextNum)<=finalSum){
            ans.emplace_back(nextNum);
            curSum += nextNum;
            nextNum += 2;
        }
        
        if (curSum < finalSum) 
            ans[ans.size()-1] += (finalSum - curSum);

        return ans;
    }
};