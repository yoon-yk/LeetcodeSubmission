class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        auto pp = people;
        sort(flowers.begin(), flowers.end());
        sort(pp.begin(), pp.end());
        
        unordered_map<int, int> bloomCount;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int flowerIndex = 0;
        for (auto & p : pp) {
            // Add flowers that are in bloom for the current p to min heap
            while (flowerIndex < flowers.size() && flowers[flowerIndex][0] <= p) {
                minHeap.push(flowers[flowerIndex][1]);
                ++flowerIndex;
            }
            
            // Remove flowers that have withered away for the current p
            while (!minHeap.empty() && minHeap.top() < p) {
                minHeap.pop();
            }
            
            bloomCount[p] = minHeap.size();
        }
        
        vector<int> ans;
        for (auto & p : people) {
            ans.push_back(bloomCount[p]);
        }
        
        return ans;
    }
};
