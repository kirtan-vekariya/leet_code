class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int  i = 0 ; i < cardPoints.size() ; i++){
            sum += cardPoints[i];
        }
        int size = cardPoints.size()-k;
        if(size == 0)return sum;
        int wsum = 0;
        for(int i = 0 ; i < size ; i++){
            wsum += cardPoints[i];
        }
        int mini = wsum;
        for(int i = size ; i < cardPoints.size() ; i++){
            wsum += cardPoints[i];
            wsum -= cardPoints[i-size];
            mini = min(mini,wsum);
        }
        return sum - mini;
    }
};