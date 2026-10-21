class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxi = 0;
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0 && cnt <= k){
                cnt++;
            }
            if(nums[i] ==0 && cnt > k){
                while(cnt > k){
                    if(nums[left] == 0)cnt--;
                    left++;
                }
            }
            maxi = max(maxi, i - left + 1);
        }
        return maxi;
    }
};