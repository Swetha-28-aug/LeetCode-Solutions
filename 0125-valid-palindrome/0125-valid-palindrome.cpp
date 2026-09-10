class Solution {
public:
    bool isPalindrome(string s) {
        string news;
        if(s.empty()) return true;
        for(int i=0;s[i];i++){
            if(isalnum(s[i])){
                s[i]=tolower(s[i]);
                news+=(s[i]);
            }
        }
        int n=news.length();
        for(int i=0;i<n/2;i++){
            if(news[i]!=news[n-1-i]){
                return false;
            }
        }
        return true;
    }
};