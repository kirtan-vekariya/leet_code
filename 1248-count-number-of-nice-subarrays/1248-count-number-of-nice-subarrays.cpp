class Solution {
public:
int f(vector<int>& nums, int k){
    int left = 0;
    int sum = 0;
    int cnt = 0;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++){
        sum += nums[i];
        while(sum > k){
            sum -= nums[left];
            left++;
        }
        cnt += i - left + 1;
    }
    return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0)nums[i] = 0;
            else nums[i] = 1;
        }
        return f(nums, k) - f(nums, k - 1);
    }
};