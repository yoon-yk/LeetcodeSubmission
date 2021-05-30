class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i, size = nums.size();
        int *temp = new int[size];
        for(i=0; i<size; i++){
            temp[(i+k)%size] = nums[i];
        }
        for(i=0; i<size; i++){
            nums[i] = temp[i];
        }
    }
};