class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = nums[0];
        int mini = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            sum += nums[i];
            mini = min(mini, nums[i]);
        }
        return sum - nums.size() * mini;
    }
};