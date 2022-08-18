class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        auto compare = [] (pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        };
        
        // put into the hashMap
        unordered_map<int, int> hashM;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> maxHeap(compare);
        for (int i : arr)
            hashM[i] ++;
        
        // put into the priority queue
        for (auto i : hashM)
            maxHeap.push({i.first, i.second});
        
        int ans = 0;
        int targetSize = arr.size() >> 1, curSize = arr.size();
        while (curSize > targetSize) {
           auto cur = maxHeap.top(); maxHeap.pop();
            curSize -= cur.second;
            ans++;
        }
        
        return ans;
    }
};