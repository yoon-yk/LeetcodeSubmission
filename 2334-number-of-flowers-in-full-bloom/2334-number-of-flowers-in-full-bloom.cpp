class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        auto pp = people;
        sort(flowers.begin(), flowers.end());
        sort(pp.begin(), pp.end());
        
        unordered_map<int, int> bloomCount;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int flowerIndex = 0;
        for (int person : pp) {
            // Add flowers that are in bloom for the current person to min heap
            while (flowerIndex < flowers.size() && flowers[flowerIndex][0] <= person) {
                minHeap.push(flowers[flowerIndex][1]);
                ++flowerIndex;
            }
            
            // Remove flowers that have withered away for the current person
            while (!minHeap.empty() && minHeap.top() < person) {
                minHeap.pop();
            }
            
            bloomCount[person] = minHeap.size();
        }
        
        // Reconstruct the answer based on the original order of 'people'
        vector<int> ans;
        for (int person : people) {
            ans.push_back(bloomCount[person]);
        }
        
        return ans;
    }
};
