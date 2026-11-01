class Solution {
public:
int f(vector<int>& nums, int k){
    int left = 0;
    int cnt = 0;
    int n = nums.size();
    unordered_map<int, int> freq;
    for(int i = 0 ; i < n ; i++){
        freq[nums[i]]++;
        while(freq.size() > k){
            freq[nums[left]]--;
            if(freq[nums[left]] == 0)freq.erase(nums[left]);
            left++;
        }
        cnt += i - left + 1;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};