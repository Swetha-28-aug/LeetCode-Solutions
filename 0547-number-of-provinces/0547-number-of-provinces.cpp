class Solution {
public:
    int find(vector<int>&leader,int node){
      if(leader[node]!=node){
        leader[node]=find(leader,leader[node]);
      }
      return leader[node];
    }
    void join(vector<int>&leader,int left,int right){
      int lf=find(leader,left);
      int hf=find(leader,right);
      if(lf!=hf){
        leader[lf]=hf;
      }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<int>leader(n+1);
    for(int i=1;i<n+1;i++){
        leader[i]=i;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i==j) continue;
            if(isConnected[i-1][j-1]==1){
              join(leader,i,j);
            }
        }
    }
    set<int>s;
    for(int i=1;i<n+1;i++){
    s.insert(find(leader,i));

    } 
    return s.size();
    }
};