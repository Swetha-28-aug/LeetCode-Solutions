class Solution {
public:
    int maximumLengthSubstring(string s) {
      map<char,int>mp;
     int len=0,l=0;
     for(int i=0;s[i];i++){
        mp[s[i]]++;
        while(mp[s[i]]>2){
            mp[s[l]]--;
            l++;
        }
           len=max(len,i-l+1);
     }
  
     return len;
    }
};