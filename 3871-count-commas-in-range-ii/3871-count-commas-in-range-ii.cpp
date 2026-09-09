class Solution {
public:
    long long countCommas(long long n) {
    long long cnt=0;
    for(long long p=1000;p<=n;p*=1000){
        cnt+=n-p+1;
    }
    return cnt;
    }
};