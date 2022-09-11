class Solution {
public:
    const unsigned int M=1000000007;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i]={efficiency[i],speed[i]};
        }
        
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>> q;
       long long int sum=0;
       long long int ans=0;
        for(int i=0;i<n;i++){
            int curreffi=arr[i].first;
            int currSpeed=arr[i].second;
            if(q.size()==k){
                int top=q.top();
                if(top<currSpeed){
                    
                    q.pop();
                    q.push(currSpeed);
                    sum+=(currSpeed-top);
                    
                }
            }
            else{
                q.push(currSpeed);
                sum+=currSpeed;
            }
            ans=max(ans,sum*curreffi);
        }
        return ans%M;
    }
};