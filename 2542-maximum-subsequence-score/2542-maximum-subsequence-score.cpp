class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
     
        /*
        [3, 1, 3, 2]
        [1, 2, 3, 4]
        */
        
        int n = nums1.size();
        
        vector<pair<int, int>> v2;
        for (int i=0; i<n; ++i) {
            v2.push_back({nums2[i], i});
        }
        sort(v2.begin(), v2.end());
        
        vector<int> v1;
        for (int i=0; i<n; ++i) {
            v1.push_back(nums1[v2[i].second]);
        }
        
        long long ans = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i=n-1; i>=0; --i) {
            long long minV = v2[i].first;
            pq.push(v1[i]);
            sum += v1[i];
            

            if (pq.size() == k+1) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, sum * minV);
            }

        }
        
        return ans;
        
    }

};