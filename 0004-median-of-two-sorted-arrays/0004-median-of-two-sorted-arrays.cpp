class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long long n=nums1.size();
        long long m=nums2.size();
        vector<int> arr;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            arr.push_back(nums2[j]);
            j++;
        }
        long long a = arr.size();
        if(a%2 != 0){
            return arr[(a/2)];
        }
        else{
            return ((arr[a/2-1] + arr[a/2]) / 2.0);
        }
    }
};