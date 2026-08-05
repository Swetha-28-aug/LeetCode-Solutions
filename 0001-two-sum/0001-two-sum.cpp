class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
 map<int,int>mp;
 int n=nums.size();
 for(int i=0;i<n;i++){
    int diff=target-nums[i];
    if(mp.count(diff)){
        return {i,mp[diff]};
    }
    mp[nums[i]]=i;
 }
return {};
 }
};