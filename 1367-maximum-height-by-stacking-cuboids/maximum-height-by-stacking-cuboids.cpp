class Solution {
public:
    static bool comp(vector<int>&d1,vector<int>&d2){
        if(d1[0]==d2[0]){
            if(d1[1]==d2[1]){
                return d1[2]<d2[2];
            }
            return d1[1]<d2[1];
        }
        return d1[0]<d2[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size()+1,0));
        sort(cuboids.begin(),cuboids.end(),comp);
        for(int pos=cuboids.size()-1;pos>=0;pos--){
            for(int prev=pos;prev>=-1;prev--){
                int skip=dp[pos+1][prev+1];
                int take=0;
                  if(prev == -1 || (cuboids[prev][0] <= cuboids[pos][0] && cuboids[prev][1] <= cuboids[pos][1] && cuboids[prev][2] <= cuboids[pos][2]))
                take=cuboids[pos][2]+dp[pos+1][pos+1];
            dp[pos][prev+1]=max(skip,take);
            }


        }
        return dp[0][0];

    }
};