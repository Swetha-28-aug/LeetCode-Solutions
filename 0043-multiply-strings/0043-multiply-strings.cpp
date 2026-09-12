class Solution {
public:
    string multiply(string num1, string num2) {
    int n=num1.size();
    int m=num2.size();
    vector<int>pos(n+m,0);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int mul=(num1[i]-'0')*(num2[j]-'0');
            int p1=i+j;
           int  p2=p1+1;
            int sum=mul+pos[p2];
            pos[p1]+=sum/10;
            pos[p2]=sum%10;
        }
    }
    string res;
    for(int i:pos){
        if(!(res.empty() && i==0))
        res.push_back(i+'0');
    }
    return (res.empty())? "0":res;
    }
};