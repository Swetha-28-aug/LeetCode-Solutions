class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
 stack<int>stk;
 int maxarea=0;
 int n=heights.size();
 for(int i=0;i<heights.size();i++){
         while(!stk.empty() && heights[i]<heights[stk.top()]){
            int curr1=heights[stk.top()];
            stk.pop();
            int curr=curr1*(stk.empty()?i:i-stk.top()-1);
            maxarea=max(maxarea,curr);
         }
         stk.push(i);

 }
 while(!stk.empty()){
    int curr1=heights[stk.top()];
    stk.pop();
    int curr=curr1*(stk.empty()?n:n-stk.top()-1);
    maxarea=max(maxarea,curr);
 }
 return maxarea;

    }
};