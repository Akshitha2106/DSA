class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>graph;
        vector<int>inD(n,0);

        for(auto edge:relations){
            int x=edge[0]-1;
            int y=edge[1]-1;
            graph[x].push_back(y);
            inD[y]++;
        }
        queue<int>q;
        vector<int>maxTime(n,0);

        for(int i=0;i<n;i++){
            if(inD[i]==0){
                q.push(i);
                maxTime[i]=time[i];
            }
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto it:graph[node]){
                    maxTime[it]=max(maxTime[it],maxTime[node]+time[it]);
                inD[it]--;
                if(inD[it]==0){
                    q.push(it);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,maxTime[i]);
        }

        return ans;
    }
};