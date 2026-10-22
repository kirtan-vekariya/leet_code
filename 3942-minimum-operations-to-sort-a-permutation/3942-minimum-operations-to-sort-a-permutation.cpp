class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        bool isinc = true;
        bool isdec = true;
        int pos0 = -1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0)pos0 = i;
            if(nums[(i + 1) % n] != (nums[i] + 1) % n)isinc = false;
            if(nums[(i + 1) % n] != (nums[i] - 1 + n) % n)isdec = false;
        }
        if(isinc)return min(pos0, n - pos0 + 2);
        if(isdec)return min(n - pos0, pos0 + 2);
        return -1;
    }
};