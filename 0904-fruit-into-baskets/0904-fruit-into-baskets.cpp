class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> basket;
        int left = 0;
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            basket[fruits[i]]++;
            while(basket.size() > 2){
                basket[fruits[left]]--;
                if(basket[fruits[left]] == 0)basket.erase(fruits[left]);
                left++;
            }
            maxi = max(maxi, i - left + 1);
        }
        return maxi;
    }
};