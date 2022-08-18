class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        // put into the hashMap
        unordered_map<int, int> hashM;
        priority_queue<int> maxHeap;
        for (int i : arr)
            hashM[i] ++;
        
        // put into the priority queue
        for (auto i : hashM)
            maxHeap.push(i.second);
        
        int ans = 0;
        int targetSize = arr.size() >> 1, curSize = arr.size();
        while (curSize > targetSize) {
           int cur = maxHeap.top(); maxHeap.pop();
            curSize -= cur;
            ans++;
        }
        
        return ans;
    }
};