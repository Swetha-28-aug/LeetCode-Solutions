class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int ans=nums[0];
     int maxi=nums[0];
     for(int i=1;i<nums.size();i++){
        ans=max(nums[i],ans+nums[i]);
        maxi=max(maxi,ans);
     }
     return maxi;
    }
};