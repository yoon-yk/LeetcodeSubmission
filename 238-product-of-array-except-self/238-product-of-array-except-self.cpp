class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int left[size], right[size];
        vector<int> answer;
        left[0] = right[size-1] = 1;
        for (int i=1; i<size; i++)
            left[i] = left[i-1]*nums[i-1];
        for (int j=size-2; j>=0; j--)
            right[j] = right[j+1]*nums[j+1];
        
        for (int i=0; i<size; i++)
            answer.push_back(left[i]*right[i]);
        return answer;
    }
};