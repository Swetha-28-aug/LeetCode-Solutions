class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int n=nums.size();
       long val=0;
       long sum=0;
       for(int i=0;i<n;i++){
         val+=(i*nums[i]);
         sum+=nums[i];
       }
       long ans=val;
        for(int i=n-1;i>0;i--){
          val=val-(nums[i]*(n-1))+(sum-nums[i]);
          ans=max(val,ans);
        }
       return (int)ans;
    }
};