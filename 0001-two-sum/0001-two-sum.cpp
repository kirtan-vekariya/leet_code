class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> seen;
        for(int i = 0 ; i < nums.size() ; i++){
            int a = target - nums[i];
            if(seen.find(a) != seen.end()){
                return{seen[a],i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};