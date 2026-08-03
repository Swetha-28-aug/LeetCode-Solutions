class Solution {
public:
    string longestPalindrome(string s) {
     int st=0;
     int end=0;
     for(int i=0;i<s.length();i++){
        int odd=ex(s,i,i);
        int even=ex(s,i,i+1);
        int maxi=max(odd,even);
     if(maxi>end-st){
         st=i-(maxi-1)/2;
        end=i+maxi/2;
       
     }
    }
    return s.substr(st,end-st+1);
    }

private:
    int ex(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }    
};