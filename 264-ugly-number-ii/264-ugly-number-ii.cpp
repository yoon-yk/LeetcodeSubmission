class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<long, vector<long>, greater<long>> minHeap;
        minHeap.push(1);

        long curUglyN = 1, cnt = 0;

        while (!minHeap.empty() && cnt < n) {
            curUglyN = minHeap.top(); minHeap.pop();
            while (!minHeap.empty() && curUglyN == minHeap.top())
                minHeap.pop();
            
            minHeap.push(curUglyN * 2);
            minHeap.push(curUglyN * 3);
            minHeap.push(curUglyN * 5);
            cnt++;
        }
        
        return curUglyN;
    }
};