class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int curr=0;
       int maxi=0;
       int left=0;
       unordered_set<char>myset;
       for(int right=0;right<s.length();right++){
        while(myset.count(s[right])){
            myset.erase(s[left]);
            left++;
        }
       myset.insert(s[right]);
       curr=right-left+1;
       maxi=max(curr,maxi);
       }
       return maxi;
    }
};