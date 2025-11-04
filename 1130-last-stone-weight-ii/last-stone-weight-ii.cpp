class Solution {
public:
    int helper(int idx,vector<int>&stones,int tot,int path,vector<vector<int>>&dp){
        if(idx>=stones.size()) return 0;
        if(dp[idx][path]!=-1) return dp[idx][path];

        int skip=helper(idx+1,stones,tot,path,dp);
        int take=0;
        if(2*(path+stones[idx])<=tot){
           take=stones[idx]+helper(idx+1,stones,tot,path+stones[idx],dp);
        }

        return dp[idx][path]=max(skip,take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int path=0;
        int tot=0;
        int n=stones.size();

        for(auto it:stones) tot+=it;
        vector<vector<int>>dp(n+1,vector<int>(tot,-1));
        int a=helper(0,stones,tot,path,dp);

        return tot-2*a;


    }
};